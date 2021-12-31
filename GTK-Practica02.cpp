/*
    José Juan Ojeda Granados, 29-12-2021
    Empecemos con GTK

    https://docs.gtk.org/gtk3/index.html  Fudamental

    https://gnome.pages.gitlab.gnome.org/gtk/gtk3/index.html

Compilar desde terminal con:
gcc GTK-Practica02.cpp `pkg-config --cflags --libs gtk+-3.0` -o GTK-Practica02
*/
#include <gtk/gtk.h>

static void activate(GtkApplication *Practica, gpointer user_data)
{
  GtkWidget *Ventana0 = gtk_application_window_new(Practica);
  GtkWidget *Caja00 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
  GtkWidget *Boton00 = gtk_button_new_with_label("Salir");
  GtkWidget *Boton01 = gtk_button_new_with_label("Saludar");
  GtkWidget *Caja10 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
  GtkWidget *Boton10, *Boton11, *Boton12;
  GtkWidget *Fijo = gtk_fixed_new();
  GtkWidget *EnTexto = gtk_entry_new();

  Boton10 = gtk_toggle_button_new();
  Boton11 = gtk_button_new_with_label("11");
  Boton12 = gtk_button_new_with_label("12");


  gtk_window_set_title(GTK_WINDOW(Ventana0), " ");
  gtk_window_set_default_size(GTK_WINDOW(Ventana0), 200, 200);
  gtk_container_set_border_width(GTK_CONTAINER(Ventana0), 10);
  gtk_window_set_resizable(GTK_WINDOW(Ventana0), true);

  gtk_container_add(GTK_CONTAINER (Ventana0), Caja00);
  gtk_box_pack_start(GTK_BOX(Caja00), Boton01, false, false, 6);
  gtk_box_pack_start(GTK_BOX(Caja00), Boton00, false, true, 6);
  gtk_box_pack_start(GTK_BOX(Caja00), Caja10, true, true, 10);
  gtk_box_pack_start(GTK_BOX(Caja00), EnTexto, true, false, 0);
  gtk_box_pack_start(GTK_BOX(Caja10), Boton10, true, false, 6);

  gtk_box_pack_start(GTK_BOX(Caja10), Fijo, true, false, 6);
  gtk_fixed_put(GTK_FIXED(Fijo), Boton11, 50, 50);
  gtk_fixed_put(GTK_FIXED(Fijo), Boton12, 100, 80);
  // gtk_fixed_move(GTK_FIXED(Fijo),Boton12, 150, 80);

  // gtk_box_pack_start(GTK_BOX(Caja10), Boton11, true, true, 6);
  // gtk_box_pack_start(GTK_BOX(Caja10), Boton12, true, false, 6);

  gtk_widget_set_size_request(GTK_WIDGET(Boton12), 50, 50);

  g_signal_connect_swapped(G_OBJECT(Boton00), "clicked", G_CALLBACK(gtk_widget_destroy), G_OBJECT(Ventana0));

  //g_signal_connect(G_OBJECT(Ventana0), "destroy", G_CALLBACK(gtk_main_quit), NULL);
  g_signal_connect(Ventana0, "destroy", gtk_main_quit, NULL);

  gtk_widget_show_all(Ventana0);

  gtk_main();
}

int main(int argc, char **argv)
{
  gtk_init(&argc, &argv);

  GtkApplication *Practica;
  int status;

  Practica = gtk_application_new("org.gtk.practica00", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(Practica, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(Practica), argc, argv);
  g_object_unref(Practica);

  return status;
}
