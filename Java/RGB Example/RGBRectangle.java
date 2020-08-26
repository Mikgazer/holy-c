import java.util.*;
public class RGBRectangle extends RGBObject {

	public RGBRectangle(int width, int height, int red, int green, int blue){
		this.red = red;
		this.green = green;
		this.blue = blue;
	}
	
	public int getRed(){
		return this.red;
	}
	public int getGreen(){
		return this.green;
	}
	public int getBlue(){
		return this.blue;
	}
	
	public String toString(){
		return "This object has red value of:" + this.red + " green value of:" + this.green + " blue value of: " + this.blue;
	}
	
	/*public boolean eqColor(RGBObject x){
		if(x.geRed() == this.red && x.getGreen() == this.red && x.getBlue() == this.blue){
			return true;
			else return false;
		}
	}
	*/
}
