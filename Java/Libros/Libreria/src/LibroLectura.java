
import java.io.Serializable;
import java.util.Date;


public class LibroLectura extends PublicacionDigital implements Serializable{
    
    private String nivelRecom, genero, resumen;

    public LibroLectura(String nivelRecom, String genero, String resumen, String isbn, String titulo, String autor, String editorial, long fechaPubli, double precioVenta, double precioMensual) {
        super(isbn, titulo, autor, editorial, fechaPubli, precioVenta, precioMensual);
        this.nivelRecom = nivelRecom;
        this.genero = genero;
        this.resumen = resumen;
    }

    public String getNivelRecom() {
        return nivelRecom;
    }

    public void setNivelRecom(String nivelRecom) {
        this.nivelRecom = nivelRecom;
    }

    public String getGenero() {
        return genero;
    }

    public void setGenero(String genero) {
        this.genero = genero;
    }

    public String getResumen() {
        return resumen;
    }

    public void setResumen(String resumen) {
        this.resumen = resumen;
    }
    
     public String toStringA(){
        String fin;
        fin = "\nISBN: "+this.getIsbn()+"     -TITULO: "+this.getTitulo()+"     -AUTOR "+this.getAutor()+"     -EDITORIAL "+this.getEditorial()+"     -GENERO: "+this.getGenero()+"     -NIVEL: "+this.getNivelRecom()+"     -RESUMEN: "+this.getResumen()+"     -PRECIO COMPRA: "+this.getPrecioVenta()+"     -PRECIO CONSULTA "+this.getPrecioMensual()+"\n";
           
    return fin;
    }
    
}
