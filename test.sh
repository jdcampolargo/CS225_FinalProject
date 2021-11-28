#!/bin/bash

# This is a shell script to run all tests sequentially.

TEST_PARSING="test-parsing"
TEST_ADDER="test-adder"
TEST_AIRPORT="test-airport"

echo "Testing Parsing"
cd parsing/
./$TEST_PARSING
cd ..

echo "Testing Adder"
cd adder/
./$TEST_ADDER
cd ..

echo "Testing Airport"
cd airport/
./$TEST_AIRPORT
cd ..
