moneyCount = int(input())
pecahan = [100, 20, 10, 5, 1]
pecahanCount = 0
for pecahanValue in pecahan:
    pecahanCount += moneyCount // pecahanValue
    moneyCount %= pecahanValue
print(pecahanCount)