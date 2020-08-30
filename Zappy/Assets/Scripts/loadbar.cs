using UnityEngine;
using System.Collections;


public class loadbar : MonoBehaviour
{
	private static Texture2D mWhiteTex;
	private static GUIStyle  mStyle;


	//----------------------------------------
	// A appeller dans un callback unity OnGUI()
	//----------------------------------------
	public static void DrawGUI(int x, int y, int count, int total, string prefix, int width)
	{
		if (mWhiteTex==null) mWhiteTex = Resources.Load("Textures/white") as Texture2D; //Texture 8*8 (ou autre) toute blanche à placer dans Resources/Textures
		if (mStyle==null)
		{
			mStyle = new GUIStyle();
			mStyle.alignment = TextAnchor.MiddleCenter;
			mStyle.font = Resources.Load("Font/FontProgressBar") as Font; //Font Arial size 13 à placer dans Resources/Font
			mStyle.fontStyle = FontStyle.Bold;
		}
		GUI.color = Color.black;
		GUI.DrawTexture(new Rect(x, y, width+2, 18), mWhiteTex);
		GUI.color = new Color(0.8f,0,0);
		GUI.DrawTexture(new Rect(x+1,y+1,width,16), mWhiteTex);
		GUI.color = Color.white;
		float val = 1;
		if (total!=0) val = ((count)/(float)total);
		GUI.DrawTexture(new Rect(x+1, y+1, val*width, 16), mWhiteTex);
		GUI.color = Color.black;
		GUI.Label(new Rect(x, y, width+2, 18), prefix+" "+((int)(val*100))+"% ("+count+"/"+total+")", mStyle);
		GUI.color = Color.white;
	}
}