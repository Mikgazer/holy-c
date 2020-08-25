import javax.swing.*;
public class MyFrame1 {
/* Costruttore della classe */
public MyFrame1() {
	//Istanzio il nuovo oggetto JFrame
	JFrame frame = new JFrame("Primo esempio di Frame");
	//Setto le dimensioni della finestra
	frame.setSize(400, 200);
	//Questo metodo rende la finestra NON ridimensionabile
	frame.setResizable(false);
	//Setto la posizione della finestra sullo schermo
	frame.setLocation(150, 500);
	//visualizzo la finestra
	frame.setVisible(true);
	//Chiude il processo quando chiudiamo la finestra
	frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
}
//Classe statica Main
public static void main(String[] args) {
	MyFrame1 f = new MyFrame1();
	}
}
