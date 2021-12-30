/*
https://gnome.pages.gitlab.gnome.org/gtk/gtk3/

Para que funcione la compilación desde terminal
gcc GTK-Practica00-HM.cpp `pkg-config --cflags --libs gtk+-3.0` -o GTK-Practica00-HM
*/
#include <gtk/gtk.h>

/*
Esta es una función de devolución de llamada. Los argumentos de datos se ignoran en este ejemplo. Más sobre devoluciones de llamada a continuación.
*/
void hola( GtkWidget *widget, gpointer data )
{
        // Función que imprime por consola este mensaje al salir de la aplicación.
        g_print ("Hola Claudia\n");
}

gint delete_event( GtkWidget *widget, GdkEvent  *event, gpointer data )
{
        /*
        Si devuelve FALSE en el manejador de señales "delete_event", GTK emitirá la señal "destroy". Devolver VERDADERO significa que no desea que se destruya la ventana. Esto es útil para que aparezca diálogos de tipo ¿está seguro de que desea salir?.
        */
        g_print ("delete event ocurrido\n");

        // Cambiar TRUE a FALSE y la ventana principal se destruirá con un "delete_event".
        return TRUE;
}

/* Otra devolución de llamada */
void destroy( GtkWidget *widget, gpointer data )
{
        gtk_main_quit ();
}

int main( int argc, char *argv[] )
{
        /*
        Esto se llama en todas las aplicaciones GTK. Los argumentos se analizan desde la línea de comandos y se devuelven a la aplicación.
        */
        gtk_init (&argc, &argv);

        // GtkWidget declara el tipo de objetos widgets
        GtkWidget *window = gtk_window_new (GTK_WINDOW_TOPLEVEL);       // Declara una nueva ventana y asigna tipo.
        GtkWidget *button = gtk_button_new_with_label ("Hola Gabriel"); // Declara un botón con la etiqueta "Hola ...".
        GtkWidget *ejemplo;     // Ejemplo de declaración sin acción adicional.
        
        gtk_window_set_title(GTK_WINDOW(window), "Hola");
        gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

        /*
        Cuando la ventana recibe la señal "delete_event" (esto lo da el administrador de ventanas, generalmente mediante la opción "cerrar", o en la barra de título), le pedimos que llame a la función delete_event() como se definió anteriormente. Los datos pasados ​​a la función de devolución de llamada son NULL y se ignoran en la función de devolución de llamada.
        */
        g_signal_connect (G_OBJECT (window), "delete_event", G_CALLBACK (delete_event), NULL);

        /*
        Aquí conectamos el evento "destroy" a un manejador de señales. Este evento ocurre cuando llamamos a gtk_widget_destroy () en la ventana, o si devolvemos FALSE en la devolución de llamada "delete_event".
        */
        g_signal_connect (G_OBJECT (window), "destroy", G_CALLBACK (destroy), NULL);

        // Establece el ancho del borde de la ventana a sus elementos contenidos.
        gtk_container_set_border_width (GTK_CONTAINER (window), 10);

        /*
        Cuando el botón recibe la señal de "clic", llamará a la función hola() pasándole NULL como argumento.
        */
        g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (hola), NULL);

        /*
        Esto hará que la ventana sea destruida al llamar a gtk_widget_destroy (ventana) cuando "haga clic". Una vez más, la señal de destrucción podría provenir de aquí o del administrador de ventanas.
        */
        g_signal_connect_swapped (G_OBJECT (button), "clicked", G_CALLBACK (gtk_widget_destroy), G_OBJECT (window));

        // Esto empaqueta el botón en la ventana (un contenedor gtk).
        gtk_container_add (GTK_CONTAINER (window), button);

        // El paso final es mostrar este widget recién creado y la ventana.
        gtk_widget_show (button);
        gtk_widget_show (window);

        /*
        Todas las aplicaciones GTK deben tener un gtk_main(). El control termina aquí y espera a que ocurra un evento (como presionar una tecla o un evento del mouse).
        */
        gtk_main();

        return 0;
}
