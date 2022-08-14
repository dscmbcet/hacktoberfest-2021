//Given two strings s1 and s2, find the index of the first occurrence of s2 in s1 as a substring.
//If no such occurence exists, return -1.

import java.util.*;

public class SearchSubstring {
	public static void main(String[] args) {
		// int res = findStartIndexOfSubString("helloworld","low");

		Scanner sc = new Scanner(System.in);
		String s1, s2;
		s1 = sc.nextLine();
		s2 = sc.nextLine();
		int res = findStartIndexOfSubString(s1, s2);
		System.out.println(res);
    
	}

	static int findStartIndexOfSubString(String s1, String s2) {
    
		return s1.indexOf(s2);
    
	}
}
