#!/usr/bin/env python3
"""Find and delete duplicate LeetCode submissions, keeping the one with the best runtime."""

import os
import hashlib
import re
from collections import defaultdict

SOLVED_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "solved-leetcode")

def parse_runtime_ms(filename):
    """Extract runtime in ms from filename. Returns float('inf') if unparseable."""
    m = re.search(r'runtime (\d+)ms', filename)
    return int(m.group(1)) if m else float('inf')

def md5_file(filepath):
    h = hashlib.md5()
    with open(filepath, 'rb') as f:
        h.update(f.read())
    return h.hexdigest()

def find_and_delete_duplicates():
    total_deleted = 0
    total_kept = 0

    for problem_dir in sorted(os.listdir(SOLVED_DIR)):
        problem_path = os.path.join(SOLVED_DIR, problem_dir)
        if not os.path.isdir(problem_path):
            continue

        # Group files by content hash
        hash_groups = defaultdict(list)
        for fname in os.listdir(problem_path):
            fpath = os.path.join(problem_path, fname)
            if os.path.isfile(fpath):
                hash_groups[md5_file(fpath)].append(fname)

        # Process groups with duplicates
        for h, files in hash_groups.items():
            if len(files) <= 1:
                total_kept += len(files)
                continue

            # Sort by runtime (ascending), keep the best
            files.sort(key=parse_runtime_ms)
            keep = files[0]
            duplicates = files[1:]

            print(f"\n[{problem_dir}] Keeping: {keep}")
            for dup in duplicates:
                fpath = os.path.join(problem_path, dup)
                os.remove(fpath)
                print(f"  Deleted: {dup}")

            total_deleted += len(duplicates)
            total_kept += 1

    print(f"\n{'='*60}")
    print(f"Summary: Deleted {total_deleted} duplicates, kept {total_kept} unique files.")

if __name__ == "__main__":
    find_and_delete_duplicates()
