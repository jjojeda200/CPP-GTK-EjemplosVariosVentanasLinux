#include <gtk/gtk.h>

void on_boton10(GtkWidget *widget, gpointer dato);

static void activate(GtkApplication *Practica, gpointer user_data)
{
  GtkWidget *Ventana0 = gtk_application_window_new(Practica);
  GtkWidget *Caja00 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
  GtkWidget *Boton00 = gtk_button_new_with_label("Salir");
  GtkWidget *Boton01 = gtk_button_new_with_label("Saludar");
  GtkWidget *Caja10 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
  GtkWidget *Boton10, *Boton11, *Boton12;

  Boton10 = gtk_toggle_button_new();
  Boton11 = gtk_button_new();
  Boton12 = gtk_button_new();


  gtk_window_set_title(GTK_WINDOW(Ventana0), " ");
  // gtk_window_set_default_size(GTK_WINDOW(Ventana0), 100, 100);
  gtk_container_set_border_width(GTK_CONTAINER(Ventana0), 10);
  gtk_window_set_resizable(GTK_WINDOW(Ventana0), true);

  gtk_container_add(GTK_CONTAINER (Ventana0), Caja00);
  gtk_box_pack_start(GTK_BOX(Caja00), Boton01, false, false, 6);
  gtk_box_pack_start(GTK_BOX(Caja00), Boton00, false, true, 6);
  gtk_box_pack_start(GTK_BOX(Caja00), Caja10, true, true, 10);
  gtk_box_pack_start(GTK_BOX(Caja10), Boton10, true, false, 6);
  gtk_box_pack_start(GTK_BOX(Caja10), Boton11, true, true, 6);
  gtk_box_pack_start(GTK_BOX(Caja10), Boton12, true, false, 6);



  g_signal_connect_swapped(G_OBJECT(Boton00), "clicked", G_CALLBACK(gtk_widget_destroy), G_OBJECT(Ventana0));
  g_signal_connect(G_OBJECT(Ventana0), "destroy", G_CALLBACK(gtk_main_quit), NULL);

  gtk_widget_show_all(Ventana0);

  gtk_main();
}

void on_boton10(GtkWidget *widget, gpointer)
{
  if (gtk_toggle_action_get_active(GtkToggleAction(widget)))
  {
    g_print("Activado\n");
  }

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
