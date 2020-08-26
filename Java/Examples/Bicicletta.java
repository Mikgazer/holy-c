
public class Bicicletta extends Veicoli {

	public final int NRuote = 2;
	
	public Bicicletta() {
		this.setVelocita(0);
		this.setAccelerazione(0);
		this.setNRoute(NRuote);
	}
	
	public void pedala(int numeroPedalate, int secondi) {
		this.setAccelerazione(numeroPedalate / (secondi * secondi));
		this.setVelocita(this.getVelocita() + this.getAccelerazione() * secondi);
		
	}
}
