package parking;

import java.io.Serializable;

public class Automovil extends Vehiculo implements Serializable {

    private String tipo;
    
  

    @Override
    public double calcularImporte() {

        double factura = this.getMinutos() / 60;

        if (getTipo() == "Turismo") {
            factura *= 1.5;
        } else if (getTipo() == "Todoterreno") {
            factura *= 2.5;
        } else if (getTipo() == "Furgoneta") {
            factura *= 3.5;
        }

        if (this.isAbono()) {
            factura = factura - (factura *0.4);
        }

        return factura;
    }

    /**
     * @return the tipo
     */
    public String getTipo() {
        return tipo;
    }

    /**
     * @param tipo the tipo to set
     */
    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

}
