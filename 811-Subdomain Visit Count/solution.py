from collections import Counter

class Solution:
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        c = Counter()
        for words in cpdomains:
            words_split = words.split()
            nums = int(words_split[0])
            domains_list = words_split[1].split('.')
            domains_list.reverse()
            single_word = ""
            for i in range(len(domains_list)):
                if(i==0):
                    single_word = domains_list[i]
                else:
                    join_str = (domains_list[i], single_word)
                    single_word = ".".join(join_str)
                    #print(single_word)
                c[single_word] += nums
            
        li = []
        for key,value in c.items():
            msg = str(value) + " " + key
            li.append(msg)
        return li
                
            