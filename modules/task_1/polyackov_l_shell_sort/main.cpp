﻿// Copyright 2023 Polyackov Lev
#include "../../modules/task_1/polyackov_l_shell_sort/polyackov_l_shell_sort_seq.h"
#include <gtest/gtest.h>
#include <algorithm>

const int num_of_elems = 15;
const int num_of_parts = 4;
const int random_gen_seed = 0;

//void PrintVec(std::vector<int> tmp) {
//  for (auto& Elem : tmp) {
//    std::cout << Elem << ' ';
//  }
//  std::cout << '\n';
//}

TEST(Sequential, Test_Sorted_Array) {
  std::vector<int> tmp = get_random_vec(num_of_elems, random_gen_seed);
  std::sort(tmp.begin(), tmp.end());
  std::vector<int> res = shell_sort_with_simple_merge_seq(tmp, num_of_parts);
  for (int i = 1; i < res.size(); i++) {
    ASSERT_LE(res[i - 1], res[i]);
  }
}

TEST(Sequential, Test_Reverse_Sorted_Array) {
  std::vector<int> tmp = get_random_vec(num_of_elems, random_gen_seed);
  std::sort(tmp.rbegin(), tmp.rend()); // reverse iterators
  std::vector<int> res = shell_sort_with_simple_merge_seq(tmp, num_of_parts);
  for (int i = 1; i < res.size(); i++) {
    ASSERT_LE(res[i - 1], res[i]);
  }
}

TEST(Sequential, Test_Partially_Sorted_Array) {
  std::vector<int> tmp = get_random_vec(num_of_elems, random_gen_seed);
  int delta = 3; // delta * 2 элемента будут отсортированы в середине массива
  std::sort(tmp.begin() + num_of_elems / 2 - delta, tmp.begin() + num_of_elems / 2 + delta);
  std::vector<int> res = shell_sort_with_simple_merge_seq(tmp, num_of_parts);
  for (int i = 1; i < res.size(); i++) {
    ASSERT_LE(res[i - 1], res[i]);
  }
}

TEST(Sequential, Test_Array_With_Repeating_Elements) {
  std::vector<int> tmp = get_random_vec(num_of_elems, random_gen_seed);
  int delta = 3; // delta * 2 элемента будут изменены в середине массива
  for (int i = num_of_elems / 2 - delta; i < num_of_elems / 2; i++) {
    tmp[i] = tmp[i - 1];
  }
  for (int i = num_of_elems / 2 + delta; i > num_of_elems / 2; i--) {
    tmp[i] = tmp[i + 1];
  }
  std::vector<int> res = shell_sort_with_simple_merge_seq(tmp, num_of_parts);
  for (int i = 1; i < res.size(); i++) {
    ASSERT_LE(res[i - 1], res[i]);
  }
}

TEST(Sequential, Test_Array_Whose_Values_Are_All_The_Same) {
  std::vector<int> tmp(num_of_elems, 42);
  std::vector<int> res = shell_sort_with_simple_merge_seq(tmp, num_of_parts);
  for (int i = 1; i < res.size(); i++) {
    ASSERT_LE(res[i - 1], res[i]);
  }
}
