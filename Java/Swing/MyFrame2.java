
import javax.swing.*;
public class MyFrame2 extends JFrame {
	public MyFrame2(String titolo) {
	super(titolo);
	setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
	setBounds(50, 50, 150, 500);
	setVisible(true);
}
public MyFrame2() {
	super();
	setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
	setBounds(250, 50, 150, 500);
	setVisible(true);
}

public static void main(String[] args) {
	MyFrame2 finestra1 = new MyFrame2("Prova!");
	MyFrame2 finestra2 = new MyFrame2();
	}
}
