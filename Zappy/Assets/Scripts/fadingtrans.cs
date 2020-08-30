using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class fadingtrans : MonoBehaviour
{
    public Texture2D fadeOutTexture;
    public float fadeSpeed = 0.8f;
    private int drawDepth = -1000;
    private float alpha = 1.0f;
    private int fadeDir = -1;
    bool ife = false;
    public GameObject save;
    public string scene;
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

    public float BeginFade(int direction)
    {
        fadeDir = direction;
        return (fadeSpeed);
    }

    private void Update()
    {
        if ((Time.time - go) >= 2 && check == true)
        {
            LoadScene();
        }
        if ((Time.time - go) >= 4 && check == true)
        {
            fadeSpeed = 0.3f;
            BeginFade(-1);
        }
    }

    public void OnLevelWasLoaded()
    {
        int i = 0;
        fadeSpeed = 0f;
        BeginFade(1);
        go = Time.time;
        fadeSpeed = 0.8f;
    }

    void time()
    {
        if ((Time.time - go) >= 1)
        {
            fadeSpeed = 0.3f;
            BeginFade(-1);
        }
        LoadScene();
    }

    void time2()
    {
        if ((Time.time - go) >= 1)
        {
            fadeSpeed = 0.3f;
            BeginFade(-1);
        }
    }

    public void click()
    {
        check = true;
        check2 = false;
        ok = false;
        ife = true;
        go = Time.time;
        fadeSpeed = 0.3f;
        BeginFade(1);
    }


    public void LoadScene()
    {
        DontDestroyOnLoad(save);
        SceneManager.LoadScene(scene);
    }
}