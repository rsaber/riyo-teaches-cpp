
wams = [100, 2, 3, 4, 50]


hds = 0
ds=0
crs=0
ps=0
fs=0

for wam in wams:
    if 85 <= wam and wam <= 100:
        hds+=1
    elif 75 <= wam and wam <= 84 :
        ds+=1
    elif 65 <= wam and wam <= 74 :
        crs+=1
    elif 50 <= wam and wam <= 64 :
        ps+=1
    else:
        fs+=1

gpa = (4 * (hds + ds) + 3*(crs) + 2*(ps)) / len(wams)

print(gpa)
