
package parking;

import java.io.Serializable;
import java.util.Date;

public abstract class Vehiculo {
    private String matricula;
    private Date entrada, salida;
    private boolean abono;

    public String getMatricula() {
        return matricula;
    }

    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }

    public Date getEntrada() {
        return entrada;
    }

    public void setEntrada(Date entrada) {
        this.entrada = entrada;
    }

    public Date getSalida() {
        return salida;
    }

    public void setSalida(Date salida) {
        this.salida = salida;
    }

    public boolean isAbono() {
        return abono;
    }

    public void setAbono(boolean abono) {
        this.abono = abono;
    }

    public double getMinutos() {
        return calcularMinutos(entrada,salida);
    }


    abstract public double calcularImporte();
    
    public double calcularMinutos(Date e, Date s){
        return (s.getTime()-e.getTime())/60000;
    }
    
 
}

    

