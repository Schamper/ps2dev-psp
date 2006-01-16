#include "pspgl_internal.h"


void glDrawBuffer(GLenum mode)
{
	struct pspgl_surface *s = pspgl_curctx->draw;

	switch (mode) {
	case GL_BACK:
		s->draw = &s->color_back;
		break;
	case GL_FRONT:
		s->draw = &s->color_front;
		break;
	default:
		/* XXX IMPROVE: support front & aux buffers */
		GLERROR(GL_INVALID_ENUM);
	}
}

