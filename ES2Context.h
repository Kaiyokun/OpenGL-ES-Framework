#ifndef ES_2_CONTEXT_H
#define ES_2_CONTEXT_H

#ifdef __APPLE__

    #include <opengles/es2/gl.h>

#else

    #include <gles2/gl2.h>

#endif // __APPLE__

struct ES2Context
{
    /**************************** VertexArrayData *****************************/
    struct
    {
        /// vec4
        struct
        {
            GLfloat X;
            GLfloat Y;
            GLfloat Z;
            GLfloat W;

        } GenericVertexAttributes[GL_MAX_VERTEX_ATTRIBS];

        /// glVertexAttribPointer
        struct
        {
            GLboolean Enabled;
            GLint     Size;
            GLsizei   Stride;
            GLenum    Type;
            GLboolean Normalized;
            GLvoid*   Pointer;

        } VertexAttribArrayProperties[GL_MAX_VERTEX_ATTRIBS];

        /// glBindBuffer
        struct
        {
            GLuint CurrentBufferBinding;
            GLuint ElementArrayBufferBinding;
            GLuint AttribArrayBufferBindings[GL_MAX_VERTEX_ATTRIBS];

        } BufferBindings;

        /// glBufferData
        struct
        {
            GLsizeiptr Size;
            GLenum     Usage;
            GLvoid*    Data;
            GLenum     Type;

        } VertexBufferObjects[GL_MAX_DRAW_BUFFERS];

    } VertexArrayData;

    /************************** TransformationState ***************************/
    struct
    {
        /// glViewport
        struct
        {
            GLint   LowerLeftX;
            GLint   LowerLeftY;
            GLsizei Width;
            GLsizei Height;

        } Viewport;

        /// glDepthRangef
        struct
        {
            GLclampf NearClippingPlane;
            GLclampf FarClippingPlane;

        } DepthRange;

    } TransformationState;

    /*************************** RasterizationState ***************************/
    struct
    {
        /// glLineWidth
        GLfloat LineWidth;

        /// glEnable/glDisable
        GLboolean PolygonCullingEnabled;
        GLboolean PolygonOffsetEnabled;

        /// glCullFace
        GLenum PolygonCullFacingMode;

        /// glFrontFace
        GLenum PolygonFrontfaceIndicator;

        /// glPolygonOffset
        GLfloat PolygonOffsetFactor;
        GLfloat PolygonOffsetUnits;

        /// glEnable/glDisable
        GLboolean PolygonOffsetEnabled;

    } RasterizationState;

    /**************************** PixelOperations *****************************/
    struct
    {
        /// glEnable/glDisable
        GLboolean ScissoringEnabled;
        GLboolean DepthBufferEnabled;
        GLboolean DitheringEnabled;

        /// glDepthFunc
        GLenum DepthBufferTestFunction;

        /// glScissor
        struct
        {
            GLint   LowerLeftX;
            GLint   LowerLeftY;
            GLsizei Width;
            GLsizei Height;

        } ScissorBox;

        // TODO
        struct Stencil;
        struct Blending;

    } PixelOperations;

    /****************************** PixelPacking ******************************/
    struct
    {
        /// glPixelStorei
        GLint PackAlignment;
        GLint UnpackAlignment;

    } PixelPacking;

    /****************************** TextureState ******************************/
    struct
    {
        /// glActiveTexture
        GLenum ActiveTextureUnit;

        /// glBindTexture
        struct
        {
            GLuint Texture2DBinding;
            GLuint TextureCubeMapBinding;
            GLuint TextureExternalBinding;

        } TextureUnits[GL_MAX_TEXTURE_IMAGE_UNITS];

        // TODO
        struct *Textures;

    } TextureState;

    /*************************** ProgramObjectState ***************************/
    struct
    {
        /// glUseProgram
        GLuint CurrentProgram;

        /// glCreateProgram
        struct
        {
            /// glAttachShader
            struct
            {
                GLuint VertexShader;
                GLuint FragmentShader;

            } AttachedShaders;

            /// glGetActiveAttrib
            struct
            {
                GLchar* Name;
                GLenum  Type;
                GLsizei Size;
                GLvoid* Value;

            } *Attributes;

            /// glGetActiveUniform
            struct
            {
                GLchar* Name;
                GLenum  Type;
                GLsizei Size;
                GLvoid* Value;

            } *Uniforms;

        } *Programs;

    } ProgramObjectState;

    /***************************** ShaderObjects ******************************/
    struct
    {
        /// glCreateShader
        GLenum ShaderType;

        /// glShaderSource
        GLchar** Source;

    } *ShaderObjects;

    /**************************** FramebufferState ****************************/
    struct
    {
        GLuint FrameBufferBinding;

    } FramebufferState;
};

#endif // ES_2_CONTEXT_H
