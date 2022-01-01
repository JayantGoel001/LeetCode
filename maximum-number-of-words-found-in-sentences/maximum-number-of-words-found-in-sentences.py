class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:
        maxi = 0
        
        for sentence in sentences:
            maxi = max(maxi,len(sentence.split(" ")))
        return maxi