using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class fading : MonoBehaviour {
    public Texture2D fadeOutTexture;
    public float fadeSpeed = 0.8f;
    public Texture newSprite;
    public Texture newSprite2;
    public GameObject Sphere;
    public Camera Camera;
    private int drawDepth = -1000;
    private float alpha = 1.0f;
    private int fadeDir = -1;
    bool ife = false;
    float go;
    bool check = false;
    bool check2 = false;
    bool ok = true;

    public void Start()
    {
    }

    private void OnGUI()
    {
        alpha += fadeDir * fadeSpeed * Time.deltaTime;

        alpha = Mathf.Clamp01(alpha);

        GUI.color = new Color(GUI.color.r, GUI.color.g, GUI.color.b, alpha);
        GUI.depth = drawDepth;
        GUI.DrawTexture(new Rect(0, 0, Screen.width, Screen.height), fadeOutTexture);
    }

    public float BeginFade (int direction)
    {
        fadeDir = direction;
        return (fadeSpeed);
    }

    public void OnLevelWasLoaded()
    {
        int i = 0;
        fadeSpeed = 0f;
        go = Time.time;
        fadeSpeed = 0.8f;
    }

    private void Update()
    {
        if (check == true)
        {
            time();
            ife = false;
        }
        if (check2 == true)
        {
            time2();
            ok = true;
        }
        if (ok == true)
        {
            Sphere.transform.Rotate(Vector3.left * Time.deltaTime * 10, Space.World);
            Sphere.transform.Rotate(Vector3.down * Time.deltaTime * 10, Space.World);
        }
    }

    void time()
    {
            change();
            if (ife == true)
                loop();
            fadeSpeed = 0.3f;
    }

    private void loop()
    {
        Vector3 position = new Vector3(-15, 0, 141);
        Quaternion rotate = Quaternion.Euler(10, 200, 100);
        Sphere.transform.SetPositionAndRotation(position, rotate);
    }
    public void change()
    {
        Sphere.GetComponent<Renderer>().material.mainTexture = newSprite;  
        Camera.main.fieldOfView = 30;
    }

    void time2()
    {
            change2();
            fadeSpeed = 0.3f;
    }
    public void change2()
    {
        Sphere.GetComponent<Renderer>().material.mainTexture = newSprite2;
        Camera.main.fieldOfView = 40;
    }

    public void click ()
    {
        OnLevelWasLoaded();
        check = true;
        check2 = false;
        ok = false;
        ife = true;
    }

    public void click2 ()
    {
        OnLevelWasLoaded();
        check2 = true;
        check = false;
    }
}
