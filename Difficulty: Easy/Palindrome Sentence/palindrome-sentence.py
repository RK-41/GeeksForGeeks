class Solution:
    # 05.08.25 potd
    def isPalinSent(self, s: str) -> bool:
        cleaned = ''.join(char.lower() for char in s if char.isalnum())
        return cleaned == cleaned[::-1]
