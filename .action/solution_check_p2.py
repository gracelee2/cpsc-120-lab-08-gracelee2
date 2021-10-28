#!/usr/bin/env python3
#
# Copyright 2021 Michael Shafae
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
# 
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
# 
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
""" Check student's submission; requires the main file and the
    template file from the original repository. """
# pexpect documentation
#  https://pexpect.readthedocs.io/en/stable/index.html
import io
import logging
import pexpect
import subprocess
from srcutilities import solution_check_make
import os

# to run locally 
# PYTHONPATH=../.action python3 ../.action/solution_check_p1.py . mind_reader

def run(binary):
    """ Run part-1 """
    status = True
    values = (
        ('test01.txt', 'In seeking the unattainable, simplicity only gets in the way.'),
        ('test02.txt', 'Your motives for doing whatever good deed you may have in mind will be misinterpreted by somebody.'),
        ('test03.txt', 'Never trust an operating system.'),
        ('test04.txt', 'He that is giddy thinks the world turns round.'),
        )
    for index, val in enumerate(values):
        logging.info('Test %d - %s', index + 1, val)
        _status = _run(binary, val)
        status = status and _status
        #if not status:
        #    logging.error("Did not receive expected response. Halting test.")
        #    break
    return status


def _run(binary, values):
    """ This is the test for the BMR program given the inputs from run_p1 """
    status = False
    #values = list(map(str, values))
    cmd = binary + " {}".format(values[0])
    
    proc = pexpect.spawn(cmd, timeout=1)
    ##proc.logfile = sys.stdout.buffer
    out = io.BytesIO()
    #proc.logfile = out

    try:
        proc.expect(r'(?i)\s*What\'s\s+a\s+secret\s+message\s+that\s+you\'d\s+like\s+to\s+write\s+into\s+a\s+file\?\s+Type\s+your\s+message\s+out\s+and\s+when\s+you\'re\s+done\s+press\s+return\s+or\s+enter.\s*')
    except (pexpect.exceptions.TIMEOUT, pexpect.exceptions.EOF) as exception:
        logging.error('Could not find expected output.')
        logging.debug("%s", str(exception))
        logging.debug(str(proc))
        return status

    proc.sendline(values[1])

    proc.expect(pexpect.EOF)
    proc.close()

    with open(values[0]) as fh:
        contents = fh.read().rstrip('\r\n')

    if contents == values[1] and proc.exitstatus == 0:
        logging.info('++++ Pass ++++')
        os.unlink(values[0])
        status = True
    else:
        logging.error('---- Failed ----')
        logging.error('Expected: %s', values[1])
        logging.error('Received: %s', contents)
        logging.error('Proc status: %d', proc.exitstatus)
        status = False
    return status


if __name__ == '__main__':
    solution_check_make(run=run)
