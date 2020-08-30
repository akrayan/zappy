using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class fadein : MonoBehaviour
{

    public Texture2D fadeOutTexture;
    public float fadeSpeed;

    private int drawDepth = -1000;
    private float alpha = 1.0f;
    private int fadeDir = -1;

    float go;
    public int time;
    public int start;
    AsyncOperation async;

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

    void OnLevelWasLoaded()
    {
        BeginFade(-1);
    }
    // Use this for initialization 
    void Start()
    {
        go = Time.time;
        StartLoading();
    }
    void Update()
    {
        if ((Time.time - go) >= time && start == 1)
        {
            async.allowSceneActivation = true;
        }

        if ((Time.time - go) >= time / 1.5 && start == 1)
        {
            BeginFade(1);
        }
    }
    public void StartLoading()
    {
        StartCoroutine("load");
    }

    IEnumerator load()
    {
        Debug.LogWarning("ASYNC LOAD STARTED - " +
           "DO NOT EXIT PLAY MODE UNTIL SCENE LOADS... UNITY WILL CRASH");
        async = SceneManager.LoadSceneAsync("Game");
        async.allowSceneActivation = false;
        yield return async;
    }
}