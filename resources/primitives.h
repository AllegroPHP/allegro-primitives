
struct _ALLEGRO_TRANSFORM {
   float m[4][4];
};

typedef struct _ALLEGRO_COLOR ALLEGRO_COLOR;
typedef struct _ALLEGRO_TRANSFORM ALLEGRO_TRANSFORM;
typedef struct _ALLEGRO_VERTEX_DECL ALLEGRO_VERTEX_DECL;
typedef struct _ALLEGRO_BITMAP ALLEGRO_BITMAP;

extern bool al_init_primitives_addon(void);
extern void al_draw_line(float x1, float y1, float x2, float y2, ALLEGRO_COLOR* color, float thickness);
extern ALLEGRO_COLOR* al_map_rgb(int r, int g, int b);
extern void al_flip_display(void);
extern void al_identity_transform(ALLEGRO_TRANSFORM* trans);
extern void al_rotate_transform(ALLEGRO_TRANSFORM* trans, float theta);
extern void al_translate_transform(ALLEGRO_TRANSFORM* trans, float x, float y);
extern void al_use_transform(const ALLEGRO_TRANSFORM* trans);
extern const ALLEGRO_TRANSFORM* al_get_current_transform(void);
extern void al_clear_to_color(ALLEGRO_COLOR* color);
extern int al_draw_prim(const void* vtxs, const ALLEGRO_VERTEX_DECL* decl, ALLEGRO_BITMAP* texture, int start, int end, int type);
extern void al_scale_transform(ALLEGRO_TRANSFORM* trans, float sx, float sy);