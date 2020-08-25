
import javax.swing.*;
import java.awt.*;
public class MyFrame3 extends JFrame {
	
	public MyFrame3(String titolo) {
	super(titolo);
	this.setSize(400, 500);
	Container c = this.getContentPane();
	JPanel pannello = new JPanel();
	c.add(pannello);
	setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
	setVisible(true);
}
public static void main(String[] args) {
	MyFrame3 finestra = new MyFrame3("Finestra con Pannello!");
	}
}
