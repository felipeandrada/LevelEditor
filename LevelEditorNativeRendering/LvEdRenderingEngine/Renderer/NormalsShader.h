//Copyright � 2014 Sony Computer Entertainment America LLC. See License.txt.

#pragma once

#pragma once
#include <D3DX11.h>
#include "../Core/WinHeaders.h"
#include "Shader.h"
#include "RenderEnums.h"
#include "Renderable.h"

struct ID3D11Device;
struct ID3D11VertexShader;
struct ID3D11PixelShader;
struct ID3D11GeometryShader;       
struct ID3D11Buffer;    
struct ID3D11InputLayout;
struct ID3D11RasterizerState;
struct ID3D11DepthStencilState;
struct ID3D11BlendState;

namespace LvEdEngine 
{
    class NormalsShader : public Shader
    {
    public:
        NormalsShader(ID3D11Device* device);
        virtual ~NormalsShader();

        virtual void Begin(RenderContext* rc);
        virtual void End();
        virtual void SetRenderFlag(RenderFlagsEnum rf);
        virtual void DrawNodes(const RenderNodeList& renderNodes);

        void SetColor(float4 wireColor);
        

    private:
        ID3D11Buffer*          m_cbPerFrame;
        ID3D11Buffer*          m_cbPerObject;        
        
        ID3D11VertexShader*    m_vsShader;
        ID3D11PixelShader*     m_psShader;
        ID3D11GeometryShader*  m_gsShader;
        ID3D11InputLayout*     m_layoutP;
        
        RenderContext*         m_rcntx; // render context
        
        struct CbPerFrame
        {
            Matrix ViewProj;
            float4 ViewPort;
            float4 color;
        };

        struct CbPerObject
        {
            Matrix worldXform;
            Matrix worldInvTrans;
        };
        
    };
}