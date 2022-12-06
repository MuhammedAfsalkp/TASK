import java.net.*;
import java.io.*;
import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.awt.Image;

public class Download {
    public static void main(String[] args)  {
        try{
         URL u=new URL("https://www.pakainfo.com/wp-content/uploads/2021/09/image-url-for-testing.jpg");
         HttpURLConnection hr =(HttpURLConnection)u.openConnection();
         if(hr.getResponseCode()==200){          
                InputStream is = new BufferedInputStream(u.openStream());
                String path=u.getFile();
                String filename = path.substring( path.lastIndexOf('/')+1, path.length() );
                FileOutputStream fs = new FileOutputStream(filename);
                OutputStream os= new BufferedOutputStream(fs); 
                byte dataBuffer[] = new byte[1024];
                int bytesRead;
                while ((bytesRead = is.read(dataBuffer, 0, 1024)) != -1) {
                    os.write(dataBuffer, 0, bytesRead);
                }
                File f = new File(filename);
                System.out.println("Size of Image = "+((float) f.length() / 1024 )+"  kb");
                BufferedImage bimg = ImageIO.read(new File(filename));
                int width          = bimg.getWidth();
                int height         = bimg.getHeight();
                System.out.println("Width of Image = "+width);
                System.out.println("Height of Image = "+height);

         }
        }catch(Exception e){
            System.out.println(e);

        }
    }
}