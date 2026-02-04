class Solution {
    public boolean isPalindrome(String s) {
        if(s.length() == 1){
            return true;
        }

        s = s.replaceAll("[^A-Za-z0-9]","").toLowerCase();

        int start = 0;
        int end = s.length() - 1;

        while (start < end){
            if (s.charAt(start) != s.charAt(end)){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
}