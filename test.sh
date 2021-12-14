#!/bin/bash

# This is a shell script to run all tests sequentially.

TEST_FINAL_PROJECT="test-final_project"

echo "Testing Final Project"
cd Final_Project/
./$TEST_FINAL_PROJECT
cd ..
