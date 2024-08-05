"""
/*****************************************************************************************************************

Implementataion of a single chain hashmap in Python.
Author: Agboola Olamidipupo Favour
Github: https://www.github.com/Olamidipupo-favour
Linkedin: https://www.linkedin.com/in/olamidipupo-agboola-6b3917237/
Portfolio: https://Olamidipupo-favour.github.io/

******************************************************************************************************************/

"""
class hashmap:
    def __init__(self,buckets:int):
        self.__buckets=buckets    
        self.__keys=[[] for _ in range(self.__buckets)]
    
    def __hash(self,key:int):
        return key%3
    
    def push(self, key:int):
        index=self.__hash(key)
        if(len(self.__keys)<index):
            raise Exception("out of bounds")
        self.__keys[index].append(key)

    def delete(self, key:int):
        index=self.__hash(key)
        if(len(self.__keys)<index):
            raise Exception("out of bounds")
        if(key not in self.__keys[index]):
            raise Exception("Key Not Found")
        self.__keys[index].remove(key)

    def __str__(self):
        data="""
====================================
"""
        for i in range(len(self.__keys)):
            data+=f"{i}======> f{str(self.__keys[i]).replace("[","").replace("]","")} \n"
        data+="===================================="
        return data
    
if __name__=="__main__":
    map=hashmap(10)
    map.push(12)
    map.push(34)
    print(map)