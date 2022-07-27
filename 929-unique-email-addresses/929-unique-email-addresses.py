class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        res = set();
        for email in emails:
            splitIdx = email.find("@")
            [localName, domainName] = email.split("@");
            localName = localName.split("+")[0];
            localName = "".join(localName.split("."))
            res.add("".join([localName, "@", domainName]))
        return len(res);
            
        