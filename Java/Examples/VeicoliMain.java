
public class VeicoliMain {

	public static void main(String args[]) {
		
		Automobile a;
		Bicicletta b;
		
		a = new Automobile("G4YLORD");
		b = new Bicicletta();
		
		a.avvia();
		a.accelera(30, 2);
		b.pedala(50, 5);
		
		a.printNRuote(a);
		b.printNRuote(b);
		a.printVelocita(a);
		b.printVelocita(b);
	}
}
