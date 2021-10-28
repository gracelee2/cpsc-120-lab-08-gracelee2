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
import re
from srcutilities import solution_check_make

# to run locally 
# PYTHONPATH=../.action python3 ../.action/solution_check_p1.py . mind_reader

def run(binary):
    """ Run part-1 """
    status = True
    values = (
       ('01_words.txt', r"\s*wittering\s+postdiastolic\s+pipkinet\s+candleball\s+unwax\s+unquiescent\s+wavingly\s+megadyne\s+shirtlike\s+whank\s+escopette\s+neuropathy\s+envassal\s+prosector\s+clotter\s+proctological\s+Moorish\s+superheterodyne\s+unvillaged\s+equiarticulate\s+End\s+of\s+file\s+reached\s+successfully!\s*",),
       ('02_words.txt', r'\s*sprew\s+periligamentous\s+overhover\s+maltolte\s+Phyllis\s+arboral\s+coaxial\s+Kiangan\s+Nereidiformia\s+defraudation\s+stereostatic\s+unshakeably\s+tardigradous\s+chocard\s+pensy\s+intersectional\s+phymatosis\s+stereometer\s+sherifa\s+cooter\s+End\s+of\s+file\s+reached\s+successfully!\s*',),
       ('03_words.txt', r'\s*unnatural\s+nonchargeable\s+gallic\s+taenioid\s+subbrachyskelic\s+fallway\s+soldierlike\s+notopteroid\s+forelive\s+paraphrase\s+touser\s+pennywort\s+webwork\s+galactopoiesis\s+ferineness\s+earhole\s+pseudoantique\s+site\s+horme\s+wheyeyness\s+End\s+of\s+file\s+reached\s+successfully!\s*',),
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

    expect_list = [
        values[1],
        pexpect.EOF,
    ]

    expect_match = proc.expect(expect_list)
    if expect_match < (len(expect_list) - 1):
        logging.info('++++ Pass ++++')
        logging.info(out.getvalue().decode("utf-8").rstrip('\r\n'))
        status = True
    else:
        logging.error('---- Failed ----')
        logging.error('Matched %s', proc.match)
        logging.error('Expected: %s', values[1])
        logging.error('Received (last 100 chars):')
        logging.error(proc.before.decode('utf-8').rstrip('\r\n'))
        status = False
    proc.close()
    if proc.exitstatus == 0:
        status = True
    return status


if __name__ == '__main__':
    solution_check_make(run=run)
