typedef struct _ALLEGRO_VERTEX_DECL ALLEGRO_VERTEX_DECL;
typedef struct _ALLEGRO_COLOR ALLEGRO_COLOR;
typedef struct _ALLEGRO_BITMAP ALLEGRO_BITMAP;
typedef struct _ALLEGRO_VERTEX_ELEMENT ALLEGRO_VERTEX_ELEMENT;
typedef struct _ALLEGRO_VERTEX ALLEGRO_VERTEX;

struct _ALLEGRO_COLOR
{
   float r, g, b, a;
};

struct _ALLEGRO_VERTEX {
  float x, y, z;
  float u, v;
  ALLEGRO_COLOR color;
};

struct _ALLEGRO_VERTEX_ELEMENT {
   int attribute;
   int storage;
   int offset;
};

uint32_t al_get_allegro_primitives_version(void);
bool al_init_primitives_addon(void);
void al_shutdown_primitives_addon(void);
void al_draw_line(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color, float thickness);
void al_draw_triangle(float x1, float y1, float x2, float y2, float x3, float y3, ALLEGRO_COLOR color, float thickness);
void al_draw_filled_triangle(float x1, float y1, float x2, float y2, float x3, float y3, ALLEGRO_COLOR color);
void al_draw_rectangle(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color, float thickness);
void al_draw_filled_rectangle(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color);
void al_draw_rounded_rectangle(float x1, float y1, float x2, float y2, float rx, float ry, ALLEGRO_COLOR color, float thickness);
void al_draw_filled_rounded_rectangle(float x1, float y1, float x2, float y2, float rx, float ry, ALLEGRO_COLOR color);
void al_calculate_arc(float* dest, int stride, float cx, float cy, float rx, float ry, float start_theta, float delta_theta, float thickness, int num_segments);
void al_draw_ellipse(float cx, float cy, float rx, float ry, ALLEGRO_COLOR color, float thickness);
void al_draw_filled_ellipse(float cx, float cy, float rx, float ry, ALLEGRO_COLOR color);
void al_draw_circle(float cx, float cy, float r, ALLEGRO_COLOR color, float thickness);
void al_draw_filled_circle(float cx, float cy, float r, ALLEGRO_COLOR color);
void al_draw_arc(float cx, float cy, float r, float start_theta, float delta_theta, ALLEGRO_COLOR color, float thickness);
void al_calculate_spline(float* dest, int stride, float points[8], float thickness, int num_segments);
void al_draw_spline(float points[8], ALLEGRO_COLOR color, float thickness);
void al_calculate_ribbon(float* dest, int dest_stride, const float *points, int points_stride, float thickness, int num_segments);
void al_draw_ribbon(const float *points, int points_stride, ALLEGRO_COLOR color, float thickness, int num_segments);

int al_draw_prim(const void* vtxs, const ALLEGRO_VERTEX_DECL* decl, ALLEGRO_BITMAP* texture, int start, int end, int type);
int al_draw_indexed_prim(const void* vtxs, const ALLEGRO_VERTEX_DECL* decl, ALLEGRO_BITMAP* texture, const int* indices, int num_vtx, int type);
ALLEGRO_VERTEX_DECL* al_create_vertex_decl(const ALLEGRO_VERTEX_ELEMENT* elements, int stride);
void al_destroy_vertex_decl(ALLEGRO_VERTEX_DECL* decl);
void al_draw_soft_triangle(ALLEGRO_VERTEX* v1, ALLEGRO_VERTEX* v2, ALLEGRO_VERTEX* v3, uintptr_t state, void (*init)(uintptr_t, ALLEGRO_VERTEX*, ALLEGRO_VERTEX*, ALLEGRO_VERTEX*), void (*first)(uintptr_t, int, int, int, int), void (*step)(uintptr_t, int), void (*draw)(uintptr_t, int, int, int));
void al_draw_soft_line(ALLEGRO_VERTEX* v1, ALLEGRO_VERTEX* v2, uintptr_t state, void (*first)(uintptr_t, int, int, ALLEGRO_VERTEX*, ALLEGRO_VERTEX*), void (*step)(uintptr_t, int), void (*draw)(uintptr_t, int, int));