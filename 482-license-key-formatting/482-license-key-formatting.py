class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        # rawStr = s.split("-");
        # first = rawStr[0];
        # rawStr = "".join(rawStr[1:]);
        # i = 0;
        # res = "";
        # curr = "";
        # for c in rawStr:
        #     curr += to_upper(c);
        #     if(len(curr) == k):
        #         res += curr + "-";
        #         curr = ""
        # if(len(first) >= 1):
        #     return first + res[:len(res) - 1]
        # return res[:len(res) - 1]
        S = S.replace("-", "").upper()[::-1]
        return '-'.join(S[i:i+K] for i in range(0, len(S), K))[::-1]