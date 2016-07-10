#include <gtk/gtk.h>

enum {
	MATRICULA_COLUMN,
	NOME_COLUMN,
	FUNCAO_COLUMN,
	NIVEL_COLUMN,
	DEPARTAMENTO_COLUMN,
	N_COLUMNS
};


void titulo(GtkWidget *list) {

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeStore *store;
  
	column = gtk_tree_view_column_new();
	gtk_tree_view_column_set_title(column, "Matrícula");
	gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_column_pack_start(column, renderer, TRUE);
	gtk_tree_view_column_add_attribute(column, renderer, "text", MATRICULA_COLUMN);

	column = gtk_tree_view_column_new();
	gtk_tree_view_column_set_title(column, "Nome");
	gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_column_pack_start(column, renderer, TRUE);
	gtk_tree_view_column_add_attribute(column, renderer, "text", NOME_COLUMN);

	column = gtk_tree_view_column_new();
	gtk_tree_view_column_set_title(column, "Função");
	gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_column_pack_start(column, renderer, TRUE);
	gtk_tree_view_column_add_attribute(column, renderer, "text", FUNCAO_COLUMN);

	column = gtk_tree_view_column_new();
	gtk_tree_view_column_set_title(column, "Nível");
	gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_column_pack_start(column, renderer, TRUE);
	gtk_tree_view_column_add_attribute(column, renderer, "text", NIVEL_COLUMN);

	column = gtk_tree_view_column_new();
	gtk_tree_view_column_set_title(column, "Departamento");
	gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_column_pack_start(column, renderer, TRUE);
	gtk_tree_view_column_add_attribute(column, renderer, "text", DEPARTAMENTO_COLUMN);

	store = gtk_tree_store_new(N_COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);//Modela os dados a serem inseridos em cada coluna

	gtk_tree_view_set_model(GTK_TREE_VIEW(list), GTK_TREE_MODEL(store));

	g_object_unref(store);
}

void init_list(GtkWidget *list) {

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeStore *store;

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("MATRÍCULA", renderer, "text", MATRICULA_COLUMN, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("NOME", renderer, "text", NOME_COLUMN, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("FUNÇÃO", renderer, "text", FUNCAO_COLUMN, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("NÍVEL", renderer, "text", NIVEL_COLUMN, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("DEPARTAMENTO", renderer, "text", DEPARTAMENTO_COLUMN, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

	store = gtk_tree_store_new(N_COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);//Inicia definindo os tipos de dados a serem inseridos em cada coluna

	gtk_tree_view_set_model(GTK_TREE_VIEW(list), GTK_TREE_MODEL(store));

	g_object_unref(store);
}

void add_to_list(GtkWidget *list, const gchar *str0, const gchar *str1, const gchar *str2, const gchar *str3, const gchar *str4) {
    
	GtkTreeStore *store;
	GtkTreeIter iter;

	store = GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(list)));

	gtk_tree_store_append(store, &iter, NULL);//Passa um iterador

	gtk_tree_store_set(store, &iter, MATRICULA_COLUMN, str0, NOME_COLUMN, str1, FUNCAO_COLUMN, str2, NIVEL_COLUMN, str3, DEPARTAMENTO_COLUMN, str4, -1);
}

void on_changed(GtkWidget *widget, gpointer label) {
    
	GtkTreeIter iter;
	GtkTreeModel *model;
	gchar *value;

	if(gtk_tree_selection_get_selected(GTK_TREE_SELECTION(widget), &model, &iter)) {
		gtk_tree_model_get(model, &iter, NOME_COLUMN, &value,  -1);
		gtk_label_set_text(GTK_LABEL(label), value);
		g_free(value);
	}
}

int main(int argc, char *argv[]) {
	GtkBuilder *builder;
	GtkWidget *window;
	GtkWidget *list;

	GtkWidget *box;

	GtkWidget *label;
	GtkTreeSelection *selection; 

	gtk_init(&argc, &argv);

	builder = gtk_builder_new();//Elemento usado para criar os Objetos Widgets

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	list = gtk_tree_view_new();

	gtk_window_set_title(GTK_WINDOW(window), "List view");
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);
	gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);

	//gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(list), TRUE);
	//gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(list), FALSE);

	box = gtk_box_new(FALSE, 0);

	gtk_box_pack_start(GTK_BOX(box), list, TRUE, TRUE, 5);

	label = gtk_label_new("");

	gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 5);

	gtk_container_add(GTK_CONTAINER(window), box);

	init_list(list);
	//titulo(list);
	add_to_list(list, "001", "Marcos Jose da Silva", "Agente Adiministrativo", "2", "Departamento de Pessoal");
	add_to_list(list, "002", "Antonio Silverio da Silva", "Diretor de Departamento", "3", "Departamento de Pessoal");

	selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(list));

	g_signal_connect(selection, "changed", G_CALLBACK(on_changed), label);

	g_signal_connect(G_OBJECT (window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
