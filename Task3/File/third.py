# Reading the file
with open("numbers.txt","r") as f:
    lines = [ line.strip() for line in f if(line.strip().isnumeric()) and line.strip() != '0' ]


# Calculating the average
evenCount=evenAverage=oddAverage=0;
for i in range(len(lines)):   
    if(int(lines[i])%2==0):
        evenCount+=1;
        evenAverage =((evenAverage*(evenCount-1))/evenCount)+(int(lines[i])/evenCount);
        print(evenAverage,lines[i],"even")
    else:
         oddAverage=((oddAverage*(i-evenCount))/ ((i+1)-evenCount)) + ( int(lines[i])/ ((i+1)-evenCount) )
         print(oddAverage,lines[i],"odd")


# Writing to a file
l="Average of even Numbers = "+str(evenAverage)+"\n"+"Average of odd Numbers = "+str(oddAverage);
with open("output.txt","w") as f:
    f.write(l);


