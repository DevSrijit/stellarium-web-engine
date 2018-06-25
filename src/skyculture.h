/* Stellarium Web Engine - Copyright (c) 2018 - Noctua Software Ltd
 *
 * This program is licensed under the terms of the GNU AGPL v3, or
 * alternatively under a commercial licence.
 *
 * The terms of the AGPL v3 license can be found in the main directory of this
 * repository.
 */

/*
 * File: Skyculture
 *
 * Functions to get stars name and constellation lines from a given
 * star culture.  For the moment we only support western names and
 * constellations
 */

#ifndef SKYCULTURE_H
#define SKYCULTURE_H

/*
 * Type: constellation_infos_t
 * Information about a given constellation.
 */
typedef struct constellation_infos
{
    char id[8];
    char name[128];
    int  lines[64][2]; // star HD number.
    int  nb_lines;
    double bounds[64][2]; // Ra/dec B1875 boundaries polygon.
    int nb_bounds;
} constellation_infos_t;

/*
 * Type: skyculture_t
 * Opaque type that represent a sky culture. */
typedef struct skyculture skyculture_t;

/* Function: skyculture_create
 * Create a new <skyculture_t> instance.  */
skyculture_t *skyculture_create(void);

/* Function: skyculture_get_star_name
 * Get the name of a given star from its HD number.
 *
 * Parameters:
 *  cult - A <skyculture_t> instance.
 *  hd   - A star Henry Draper catalog number.
 *
 * Return:
 *  The name of the star, or NULL if it is not found.
 */
const char *skyculture_get_star_name(const skyculture_t *cult, int hd);

/* Function: skyculture_search_star_name
 * Search for a star with a given name.
 *
 * Parameters:
 *  cult - A <skyculture_t> instance.
 *  name - The name of the star.
 *
 * Return:
 *  The Henry Draper catalog number of the star, or zero if it is not
 *  found.
 */
int skyculture_search_star_name(const skyculture_t *cult, const char *name);


/*
 * Function: skyculture_get_constellations
 * Return the list of all the constellations in a skyculture.
 *
 * Parameters:
 *   cult - A <skyculture_t> instance.
 *   nb   - Get the number of constellations in the list.
 *
 * Return:
 *   An array of all the constellation infos.  Terminated by an empty one.
 */
const constellation_infos_t *skyculture_get_constellations(
        const skyculture_t *cult,
        int *nb);

#endif // SKYCULTURE_H
