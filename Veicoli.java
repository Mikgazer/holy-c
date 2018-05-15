
public class Veicoli {

	private double velocita=0;
	private double accelerazione=0;
	public int NRuote;
	
	public double getVelocita() {
		return velocita;
	}
	public double getAccelerazione() {
		return accelerazione;
	}
	
	public void setVelocita(double v) {
		this.velocita = v;
	}
	public void setAccelerazione(double a) {
		this.accelerazione = a;
	}
	public void setNRoute(int n) {
		this.NRuote = n;
	}
	
	public static void printVelocita(Veicoli v) {
		System.out.println("Velocita:"+ v.velocita);
	}
	
	public void printNRuote(Veicoli v){
	System.out.println("Numero di ruote: " + v.NRuote);
	}

}
