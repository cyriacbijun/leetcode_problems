def number_words(num):
    numbers = [1000000000,1000000,1000,100,90,80,70,60,50,40,30,20,19, 18,17,16,15,14,13,12,
               11,10,9,8,7,6,5,4,3,2,1]
    words = ["billion","million","thousand","hundred","ninety","eighty","seventy","sixty",
             "fifty","forty","thirty","twenty","ninteen","eighteen","seventeen","sixteen","fifteen",
             "fourteen","thirteen","twelve","eleven","ten","nine",
             "eight","seven","six","five","four","three","two","one"]
    result = ""
    for i in range(0,31):
        if(num >= numbers[i]):
            if(num >= 100):
                result += number_words(num/numbers[i]) + " " + words[i] + " "
            else:
                result += words[i] + " "
            num %= numbers[i]
            if(num == 0):
                break
    return "Zero" if result == "" else result[0:-1]

print(number_words(1342233607))