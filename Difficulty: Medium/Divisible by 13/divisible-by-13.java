class Solution {
    // 15.07.25 potd
    public boolean divby13(String s) {
        // code here
        int num = 0;
        for(char c: s.toCharArray()){
            num = num*10 + (c-'0');
            num %=13;
        }
        return (num==0);
    }
}