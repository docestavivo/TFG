
import java.io.Serializable;
import java.util.Date;


public class LibroTexto extends PublicacionDigital implements Serializable{
    
    private String nivel, materia;
    private int curso;

    public LibroTexto(String nivel, String materia, int curso, String isbn, String titulo, String autor, String editorial, long fechaPubli, double precioVenta, double precioMensual) {
        super(isbn, titulo, autor, editorial, fechaPubli, precioVenta, precioMensual);
        this.nivel = nivel;
        this.materia = materia;
        this.curso = curso;
    }
    
    

    public String getNivel() {
        return nivel;
    }

    public void setNivel(String nivel) {
        this.nivel = nivel;
    }

    public String getMateria() {
        return materia;
    }

    public void setMateria(String materia) {
        this.materia = materia;
    }

    public int getCurso() {
        return curso;
    }

    public void setCurso(int curso) {
        this.curso = curso;
    }
    
    public String toStringA(){
        String fin;
        fin = "\nISBN: "+this.getIsbn()+"     -Editorial: "+this.getEditorial()+"     -Curso "+this.getCurso()+"º-"+this.getNivel()+"     -Materia: "+this.getMateria()+"     -Autor: "+this.getAutor()+"     -PRECIO COMPRA: "+this.getPrecioVenta()+"     -PRECIO CONSULTA "+this.getPrecioMensual()+"\n";
           
    return fin;
    }
    
    
    
}
