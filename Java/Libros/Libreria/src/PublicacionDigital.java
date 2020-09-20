
import java.io.Serializable;
import java.util.Date;


abstract class PublicacionDigital implements Serializable{
    
    private String isbn, titulo, autor, editorial;
    private long fechaPubli;
    private double precioVenta, precioMensual;
    
    

    public PublicacionDigital(String isbn, String titulo, String autor, String editorial, long fechaPubli, double precioVenta, double precioMensual) {
        this.isbn = isbn;
        this.titulo = titulo;
        this.autor = autor;
        this.editorial = editorial;
        this.fechaPubli = fechaPubli;
        this.precioVenta = precioVenta;
        this.precioMensual = precioMensual;
        
    }
    
   
    public String getIsbn() {
        return isbn;
    }

    public void setIsbn(String isbn) {
        this.isbn = isbn;
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public String getEditorial() {
        return editorial;
    }

    public void setEditorial(String editorial) {
        this.editorial = editorial;
    }

    public long getFechaPubli() {
        return fechaPubli;
    }

    public void setFechaPubli(long fechaPubli) {
        this.fechaPubli = fechaPubli;
    }

    public double getPrecioVenta() {
        return precioVenta;
    }

    public void setPrecioVenta(double precioVenta) {
        this.precioVenta = precioVenta;
    }

    public double getPrecioMensual() {
        return precioMensual;
    }

    public void setPrecioMensual(double precioMensual) {
        this.precioMensual = precioMensual;
    }
    
    abstract String toStringA();
    
    
}
