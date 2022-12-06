import requests
from PIL import Image 

try:

    res = requests.get('https://i.imgur.com/ExdKOOz.png')
    if(r.status_code==requests.codes.ok):      
        size = len(res.content)/1000;
        contentType = r.headers.get('content-type');
        filename = "download."+ contentType.split('/')[1];
        f = open(filename,'wb');
        f.write(res.content);
        f.close();
        image = Image.open(filename);
        print("Size of the image   = ",size,"KB")
        print("Width of the image  = ", image.width)
        print("Height of the image = ", image.height)
        image.close()
    else:
        print("The URL is not valid");

except Exception as e:
    print(e)

