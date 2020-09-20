
import java.io.Serializable;
import java.util.Date;


public class Diccionario extends PublicacionDigital implements Serializable {

    private String idioma, cursoRecom;

    public Diccionario(String idioma, String cursoRecom, String isbn, String titulo, String autor, String editorial, long fechaPubli, double precioVenta, double precioMensual) {
        super(isbn, titulo, autor, editorial, fechaPubli, precioVenta, precioMensual);
        this.idioma = idioma;
        this.cursoRecom = cursoRecom;
    }

    public String getIdioma() {
        return idioma;
    }

    public void setIdioma(String idioma) {
        this.idioma = idioma;
    }

    public String getCursoRecom() {
        return cursoRecom;
    }

    public void setCursoRecom(String cursoRecom) {
        this.cursoRecom = cursoRecom;
    }
    public String toStringA(){
        String fin;
        fin = "\nISBN: "+this.getIsbn()+"     -TITULO: "+this.getTitulo()+"     -IDIOMA:: "+this.getIdioma()+"     -EDITORIAL: "+this.getEditorial()+"     -PRECIO COMPRA: "+this.getPrecioVenta()+"     -PRECIO CONSULTA "+this.getPrecioMensual()+"\n";
           
    return fin;
    }
}
