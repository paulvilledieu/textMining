#!/bin/bash

test_total=0
test_done=0

printf '\n'
ref/TextMiningCompiler words.txt ref/dict.bin > /dev/null

echo "========== TEST $test_total =========="
cm1='echo "approx 0 myfox"'
echo "=> $cm1"
if diff <(echo "approx 0 myfox" | ref/TextMiningApp ref/dict.bin 2> /dev/null) <(echo "approx 0 myfox" | ./TextMiningApp dict.bin 2> /dev/null)
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
if diff <(echo "approx 1 myfox" | ref/TextMiningApp ref/dict.bin 2> /dev/null) <(echo "approx 1 myfox" | ./TextMiningApp dict.bin 2> /dev/null) 
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
if diff <(echo "approx 2 myfox" | ref/TextMiningApp ref/dict.bin 2> /dev/null) <(echo "approx 2 myfox" | ./TextMiningApp dict.bin 2> /dev/null) 
then
    test_done=$((test_done + 1))
    echo "[OK]"
else
    echo "[KO]"
fi
test_total=$((test_total + 1))
printf '\n'

echo "========== TEST $test_total =========="
cm1='echo "approx 0 test"'
echo "=> $cm1"
if diff <(echo "approx 0 test" | ref/TextMiningApp ref/dict.bin 2> /dev/null) <(echo "approx 0 test" | ./TextMiningApp dict.bin 2> /dev/null) 
then
    test_done=$((test_done + 1))
    echo "[OK]"
else
    echo "[KO]"
fi
test_total=$((test_total + 1))
printf '\n'

echo "========== TEST $test_total =========="
cm1='echo "approx 1 test"'
echo "=> $cm1"
if diff <(echo "approx 1 test" | ref/TextMiningApp ref/dict.bin 2> /dev/null) <(echo "approx 1 test" | ./TextMiningApp dict.bin 2> /dev/null) 
then
    test_done=$((test_done + 1))
    echo "[OK]"
else
    echo "[KO]"
fi
test_total=$((test_total + 1))
printf '\n'

echo "========== TEST $test_total =========="
cm1='echo "approx 2 test"'
echo "=> $cm1"
if diff <(echo "approx 2 test" | ref/TextMiningApp ref/dict.bin 2> /dev/null) <(echo "approx 2 test" | ./TextMiningApp dict.bin 2> /dev/null) 
then
    test_done=$((test_done + 1))
    echo "[OK]"
else
    echo "[KO]"
fi
test_total=$((test_total + 1))
printf '\n'

echo "========== TEST $test_total =========="
cm1='echo "approx 3 test"'
echo "=> $cm1"
if diff <(echo "approx 3 test" | ref/TextMiningApp ref/dict.bin 2> /dev/null) <(echo "approx 3 test" | ./TextMiningApp dict.bin 2> /dev/null) 
then
    test_done=$((test_done + 1))
    echo "[OK]"
else
    echo "[KO]"
fi
test_total=$((test_total + 1))
printf '\n'

echo "========== TEST $test_total =========="
cm1='echo "approx 4 test"'
echo "=> $cm1"
if diff <(echo "approx 4 test" | ref/TextMiningApp ref/dict.bin 2> /dev/null) <(echo "approx 4 test" | ./TextMiningApp dict.bin 2> /dev/null) 
then
    test_done=$((test_done + 1))
    echo "[OK]"
else
    echo "[KO]"
fi
test_total=$((test_total + 1))
printf '\n'

echo "========== TEST $test_total =========="
cm1='echo "approx 0 test\napprox 0 test\napprox 0 test\napprox 0 test\napprox 0 test"'
echo "=> $cm1"
if diff <(echo "approx 0 test\napprox 0 test\napprox 0 test\napprox 0 test\napprox 0 test" | ref/TextMiningApp ref/dict.bin 2> /dev/null) <(echo "approx 0 test\napprox 0 test\napprox 0 test\napprox 0 test\napprox 0 test" | ./TextMiningApp dict.bin 2> /dev/null) 
then
    test_done=$((test_done + 1))
    echo "[OK]"
else
    echo "[KO]"
fi
test_total=$((test_total + 1))
printf '\n'

echo "========== TEST $test_total =========="
cm1='echo "approx 0 test\napprox 1 test\napprox 2 test\napprox 3 test\napprox 4 test"'
echo "=> $cm1"
if diff <(echo "approx 0 test\napprox 1 test\napprox 2 test\napprox 3 test\napprox 4 test" | ref/TextMiningApp ref/dict.bin 2> /dev/null) <(echo "approx 0 test\napprox 1 test\napprox 2 test\napprox 3 test\napprox 4 test" | ./TextMiningApp dict.bin 2> /dev/null) 
then
    test_done=$((test_done + 1))
    echo "[OK]"
else
    echo "[KO]"
fi
test_total=$((test_total + 1))
printf '\n'

echo "========== TEST $test_total =========="
cm1='cat test/test.txt'
echo "=> $cm1"
if diff <(cat test/test.txt | ref/TextMiningApp ref/dict.bin 2> /dev/null) <(cat test/test.txt | ./TextMiningApp dict.bin 2> /dev/null) > /dev/null
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
rm ref/dict.bin