#!/bin/bash

CLR_GREEN='\033[0;32m'
CLR_YELLOW='\033[0;33m'
CLR_CYAN='\033[0;36m'
CLR_RESET='\033[0m'

if [ ! -d "Week_1" ]; then
    echo -e "\033[0;31mERROR:\033[0m Run this script from inside the Summer_Assignment_2401921530276 directory!"
    exit 1
fi

echo -e "${CLR_CYAN}Generating C files for daily LeetCode problems...${CLR_RESET}"

# Format: Week|Day|file1.c file2.c file3.c
DSA_SCHEDULE=$(cat <<EOF
1|1|two_sum.c remove_duplicates_from_sorted_array.c best_time_to_buy_and_sell_stock.c
1|2|maximum_subarray.c contains_duplicate.c maximum_average_subarray_i.c
1|3|move_zeroes.c squares_of_a_sorted_array.c container_with_most_water.c
1|4|matrix_diagonal_sum.c reshape_the_matrix.c spiral_matrix.c
1|5|valid_palindrome.c reverse_string.c longest_common_prefix.c
2|1|valid_anagram.c first_unique_character.c ransom_note.c
2|2|longest_substring_without_repeating.c permutation_in_string.c find_all_anagrams.c
2|3|find_index_of_first_occurrence.c is_subsequence.c repeated_substring_pattern.c
2|4|reverse_words_in_a_string_iii.c decode_string.c generate_parentheses.c
2|5|group_anagrams.c string_compression.c longest_palindromic_substring.c
3|1|linked_list_cycle.c reverse_linked_list.c middle_of_the_linked_list.c
3|2|merge_two_sorted_lists.c remove_nth_node_from_end.c palindrome_linked_list.c
3|3|valid_parentheses.c min_stack.c next_greater_element_i.c
3|4|daily_temperatures.c evaluate_reverse_polish_notation.c largest_rectangle_in_histogram.c
3|5|implement_queue_using_stacks.c number_of_recent_calls.c sliding_window_maximum.c
4|1|maximum_depth_of_binary_tree.c invert_binary_tree.c same_tree.c
4|2|binary_tree_inorder_traversal.c binary_tree_level_order.c binary_tree_zigzag.c
4|3|search_in_a_bst.c validate_bst.c lowest_common_ancestor_of_bst.c
4|4|path_sum.c diameter_of_binary_tree.c binary_tree_maximum_path_sum.c
4|5|symmetric_tree.c construct_binary_tree_from_preorder.c serialize_and_deserialize_binary_tree.c
EOF
)

# Parse and touch the C files
echo "$DSA_SCHEDULE" | while IFS='|' read -r week day files; do
    for file in $files; do
        touch "Week_$week/Day_$day/$file"
    done
done

echo -e "${CLR_YELLOW}Generating Java files for OOPS assignments...${CLR_RESET}"

# Week 1: Library Interface
touch Week_1/OOPS/LibraryUser.java
touch Week_1/OOPS/KidUser.java
touch Week_1/OOPS/AdultUser.java
touch Week_1/OOPS/LibraryInterfaceDemo.java

# Week 2: Playable Music Interface
touch Week_2/OOPS/Playable.java
touch Week_2/OOPS/Veena.java
touch Week_2/OOPS/Saxophone.java
touch Week_2/OOPS/Test.java

# Week 3: Compartment Abstract Class
touch Week_3/OOPS/Compartment.java
touch Week_3/OOPS/TestCompartment.java

# Week 4: Mixed OOP Basics
touch Week_4/OOPS/Arithmetic.java
touch Week_4/OOPS/ToTestInt.java
touch Week_4/OOPS/InnerClassDemo.java
touch Week_4/OOPS/Point.java
touch Week_4/OOPS/Box3d.java

echo -e "${CLR_GREEN}Boom. All 60 C files and 15 Java files created in their respective directories.${CLR_RESET}"
