
import java.io.Serializable;


public class Lector implements Serializable {
    
    private String numSerie, marca, modelo, descripcion;
    private double precio;

    public Lector(String numSerie, String marca, String modelo, String descripcion, double precio) {
        this.numSerie = numSerie;
        this.marca = marca;
        this.modelo = modelo;
        this.descripcion = descripcion;
        this.precio = precio;
    }
    
    

    public String getNumSerie() {
        return numSerie;
    }

    public void setNumSerie(String numSerie) {
        this.numSerie = numSerie;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }

    public double getPrecio() {
        return precio;
    }

    public void setPrecio(double precio) {
        this.precio = precio;
    }
    
    public String toStringA(){
        String fin = "\nNUMSERIE: "+this.getNumSerie()+"     -MARCA: "+this.getMarca()+"     -MODELO: "+this.getModelo()+"     -DESCRIPCIÓN: "+this.getDescripcion()+"     -PRECIO COMPRA: "+this.getPrecio()+"\n";
           
    return fin;
    }
    
    
    
}
