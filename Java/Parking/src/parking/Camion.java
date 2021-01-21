
package parking;

import java.io.Serializable;

public class Camion extends Vehiculo implements Serializable {
    private String ejes;
    

    @Override
    public double calcularImporte() {
        
        double factura=this.getMinutos()/60;
    
        if (getEjes()=="Menos de 3 ejes")
        factura*=4.5;   
        
        else if (getEjes()=="Más de 3 ejes")
        factura*=6.5;
        
        if (this.isAbono())
            factura = factura - (factura *0.4);
        
    return factura;
    }

    /**
     * @return the ejes
     */
    public String getEjes() {
        return ejes;
    }

    /**
     * @param ejes the ejes to set
     */
    public void setEjes(String ejes) {        
        this.ejes = ejes;
    }

}
