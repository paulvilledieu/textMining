#!/bin/bash

test_total=0
test_done=0

printf '\n'
ref/TextMiningCompiler src/test_words.txt ref/dict.bin > /dev/null

echo "========== TEST $test_total =========="
cm1='echo "approx 0 myfox"'
echo "=> $cm1"
if diff <(echo "approx 0 myfox" | ref/TextMiningApp ref/dict.bin 2> /dev/null) <(echo "approx 0 myfox" | TextMiningApp dict.bin 2> /dev/null) > /dev/null
then
    test_done=$((test_done + 1))
    echo "[OK]"
else
    echo "[KO]"
fi
test_total=$((test_total + 1))
printf '\n'

echo "========== TEST $test_total =========="
cm1='echo "approx 1 myfox"'
echo "=> $cm1"
if diff <(echo "approx 1 myfox" | ref/TextMiningApp ref/dict.bin 2> /dev/null) <(echo "approx 1 myfox" | TextMiningApp dict.bin 2> /dev/null) > /dev/null
then
    test_done=$((test_done + 1))
    echo "[OK]"
else
    echo "[KO]"
fi
test_total=$((test_total + 1))
printf '\n'

echo "========== TEST $test_total =========="
cm1='echo "approx 2 myfox"'
echo "=> $cm1"
if diff <(echo "approx 2 myfox" | ref/TextMiningApp ref/dict.bin 2> /dev/null) <(echo "approx 2 myfox" | TextMiningApp dict.bin 2> /dev/null) > /dev/null
then
    test_done=$((test_done + 1))
    echo "[OK]"
else
    echo "[KO]"
fi
test_total=$((test_total + 1))
printf '\n'

echo "============================="
echo "========== RESULTS =========="
echo "============================="

echo $test_done / $test_total