#ifndef Prof_INC_PROF_INTERNAL_H
#define Prof_INC_PROF_INTERNAL_H

// report functions

#define NUM_VALUES 4
#define NUM_TITLE 2
#define NUM_HEADER (NUM_VALUES+1)

typedef struct {
   int indent;
   char *name;
   int number;
   char prefix;
   int value_flag;
   double values[NUM_VALUES];
   double heat;

   // used internally
   void *zone;
} Prof_Report_Record;

typedef struct
{
   char *title[NUM_TITLE];
   char *header[NUM_HEADER];
   int num_record;
   int hilight;
   Prof_Report_Record *record;
} Prof_Report;


typedef struct
{
   float x0,y0;
   float sx,sy;
} GraphLocation;

extern void         Prof_free_report(Prof_Report *z);
extern Prof_Report *Prof_create_report(void);


// really internal functions

extern void Prof_graph(int num_frames,
                       void (*draw_line)(float x0, float y0, float x1, float y1, float r, float g, float b, float a),
                       void *data);

extern void Prof_init_highlevel();

extern double Prof_get_time(void);

extern int        Prof_num_zones;
extern Prof_Zone *Prof_zones[512];

extern Prof_Declare(_global);



#endif
