#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>
#include <stdlib.h>
float const vilag[] = {
    -60.2, -81, -62.3, -80.9, -64.5, -80.9, -66.3, -80.3, -64, -80.3, -61.1, -80, 0, 0, -159.2, -79.5, -161.1, -79.6, -162.4, 
    -79.3, -163.1, -78.2, -160.2, -78.7, 0, 0, -45.2, -78, -43.9, -78.5, -43.3, -80, -44.9, -80.3, -46.5, -80.6, -48.4, -80.8, 
    -50.5, -81, -52.9, -81, -54, -80.2, -51.9, -79.9, -50.4, -79.2, -49.3, -78.5, -48.2, -78, -46.7, -77.8, 0, 0, -121.2, -73.5, 
    -119.9, -73.7, -118.7, -73.5, -120.2, -74.1, -122.4, -73.3, 0, 0, -124.6, -73.8, -125.9, -73.7, -127.3, -73.5, 0, 0, -99, 
    -71.9, -97, -72.4, -98.2, -72.5, -99.4, -72.4, -100.8, -72.5, -101.7, -71.7, -100.4, -71.9, 0, 0, -68.5, -71, -68.8, -72.2, 
    -71.1, -72.5, -73.1, -72.2, -75, -71.7, -73.2, -71.2, -71.7, -70.3, -71.2, -69, -69.5, -69.6, 0, 0, -59, -64.4, -60.6, -64.3, 
    -62, -64.8, -62.1, -66.2, -63.7, -66.5, -64.9, -67.2, -65.3, -68.4, -64, -68.9, -62.6, -70, -61.5, -71.1, -61.1, -72.4, -60.8, 
    -73.7, -62, -74.4, -63.3, -74.6, -64.4, -75.3, -65.9, -75.6, -67.2, -75.8, -68.4, -76, -70.6, -76.6, -72.2, -76.7, -74, -76.6, 
    -75.6, -76.7, -76.9, -77.1, -74.8, -78.2, -76.5, -78.1, -78, -79.2, -76.6, -79.9, -75.4, -80.3, -73.2, -80.4, -71.4, -80.7, 
    -70, -81, -68.2, -81.3, -65.7, -81.5, -63.3, -81.7, -61.6, -82, -59.7, -82.4, -58.2, -83.2, -57, -82.9, -55.4, -82.6, -53.6, 
    -82.3, -51.5, -82, -49.8, -81.7, -47.3, -81.7, -44.8, -81.8, -42.2, -81.7, -40.8, -81.4, -38.2, -81.3, -36.3, -81.1, -34.4, 
    -80.9, -32.3, -80.8, -30.1, -80.6, -28.5, -80.3, -29.7, -79.3, -31.6, -79.3, -33.7, -79.5, -35.6, -79.5, -35.3, -78.1, -33.9, 
    -77.9, -32.2, -77.7, -31, -77.4, -28.9, -76.7, -27.5, -76.5, -25.5, -76.3, -23.9, -76.2, -22.5, -76.1, -21.2, -75.9, -18.9, 
    -75.4, -17.5, -75.1, -16.5, -73.9, -15.4, -73.1, -13.3, -72.7, -11.5, -72, -10.3, -71.3, -8.6, -71.7, -7.4, -71.3, -5.8, -71, 
    -4.3, -71.5, -3, -71.3, -0.7, -71.2, 0.9, -71.3, 3, -71, 5.2, -70.6, 7.1, -70.2, 8.5, -70.1, 10.2, -70.5, 12, -70.6, 13.4, -70, 
    15.1, -70.4, 17, -69.9, 19.3, -69.9, 21.5, -70.1, 22.6, -70.7, 24.8, -70.5, 27.1, -70.5, 29.2, -70.2, 31, -69.8, 32.8, -69.4, 
    33.9, -68.5, 35.3, -69, 37.2, -69.2, 38.6, -69.8, 40, -69.1, 42, -68.6, 44.1, -68.3, 45.7, -67.8, 47.4, -67.7, 49, -67.1, 50.8, 
    -66.9, 51.8, -66.2, 53.6, -65.9, 55.4, -65.9, 57.3, -66.7, 58.7, -67.3, 59.9, -67.4, 61.4, -68, 63.2, -67.8, 65, -67.6, 66.9, 
    -67.9, 68.9, -67.9, 69.6, -69.7, 67.8, -70.3, 68.9, -71.1, 67.9, -71.9, 69.9, -72.3, 71.9, -71.3, 73.3, -70.4, 74.5, -69.8, 
    76.6, -69.6, 78.4, -68.7, 80.1, -68.1, 81.5, -67.5, 82.8, -67.2, 84.7, -67.2, 86.8, -67.2, 88.4, -66.5, 89.7, -67.2, 91.6, 
    -67.1, 93.5, -67.2, 95, -67.2, 96.7, -67.2, 98.7, -67.1, 100.4, -66.9, 101.6, -66.3, 103.5, -65.7, 104.9, -66.3, 107.2, -67, 
    109.2, -66.8, 111.1, -66.4, 112.9, -66.1, 114.4, -66.1, 115.6, -66.7, 117.4, -66.9, 118.6, -67.2, 120.9, -67.2, 122.3, -66.6, 
    124.1, -66.6, 126.1, -66.6, 127.9, -66.7, 129.7, -66.6, 131.8, -66.4, 133.9, -66.3, 135.7, -65.6, 136.6, -66.8, 138.6, -66.9, 
    140.8, -66.8, 143.1, -66.8, 145.5, -66.9, 146.6, -67.9, 148.8, -68.4, 150.1, -68.6, 151.5, -68.7, 153.6, -68.9, 155.2, -68.8, 
    156.8, -69.4, 159.2, -69.6, 160.8, -70.2, 162.7, -70.7, 164.9, -70.8, 167.3, -70.8, 169.5, -71.2, 170.6, -72.4, 169.3, -73.7, 
    167.4, -74.2, 166.1, -74.4, 165, -75.1, 163.8, -75.9, 163.5, -77.1, 164.7, -78.2, 167, -78.8, 165.2, -78.9, 163.7, -79.1, 
    161.8, -79.2, 160.7, -80.2, 159.8, -80.9, 161.1, -81.3, 162.5, -82.1, 163.7, -82.4, 165.1, -82.7, 166.6, -83, 169.4, -83.8, 
    173.2, -84.4, 176, -84.2, 178.3, -84.5, 180, -84.7, 180, -90, -180, -90, -179.1, -84.1, -177.1, -84.4, -175.8, -84.1, -174.4, 
    -84.5, -172.9, -84.1, -170, -83.9, -168.5, -84.2, -167, -84.6, -164.2, -84.8, -161.9, -85.1, -158.1, -85.4, -155.2, -85.1, 
    -150.9, -85.3, -148.5, -85.6, -145.9, -85.3, -142.9, -84.6, -146.8, -84.5, -150.9, -83.9, -153.4, -83.2, -152.9, -82, -155.3, 
    -81.4, -156.8, -81.1, -154.4, -81.2, -152.1, -81, -150.6, -81.3, -148.9, -81, -146.8, -79.9, -148.1, -79.7, -149.5, -79.4, 
    -151.6, -79.3, -153.4, -79.2, -156, -78.7, -157.3, -78.4, -158.4, -76.9, -157, -77.3, -155.3, -77.2, -152.9, -77.5, -151.3, 
    -77.4, -150, -77.2, -147.6, -76.6, -146.2, -75.4, -144.3, -75.5, -141.6, -75.1, -140.2, -75.1, -138.9, -75, -136.4, -74.5, 
    -135.2, -74.3, -133.7, -74.4, -132.3, -74.3, -130.9, -74.5, -129.6, -74.5, -128.2, -74.3, -126.9, -74.4, -125.4, -74.5, -124, 
    -74.5, -122.6, -74.5, -121.1, -74.5, -118.7, -74.2, -117.5, -74, -116.2, -74.2, -113.9, -73.7, -112.9, -74.4, -111.3, -74.4, 
    -110.1, -74.8, -107.6, -75.2, -106.1, -75.1, -104.9, -74.9, -103.4, -75, -102, -75.1, -100.1, -74.9, -101.3, -74.2, -102.5, 
    -74.1, -102.9, -72.8, -101.6, -72.8, -99.1, -72.9, -97.7, -73.6, -96.3, -73.6, -95, -73.5, -93.7, -73.3, -91.4, -73.4, -89.2, 
    -72.6, -87.3, -73.2, -85.2, -73.5, -83.9, -73.5, -82.7, -73.6, -80.7, -73.5, -79.3, -73.5, -77.9, -73.4, -76.2, -74, -74.9, 
    -73.9, -72.8, -73.4, -71.6, -73.3, -70.2, -73.1, -68.9, -73, -67.1, -72, -67.9, -70.9, -68.5, -69.7, -67.6, -68.5, -67.7, 
    -67.3, -66.7, -66.6, -65.4, -65.9, -64.2, -65.2, -63, -64.6, -61.4, -64.3, -59.9, -64, -58.6, -63.4, -57.2, -63.5, 0, 0, -67.8, 
    -53.9, -66.5, -54.5, -65.5, -55.2, -67.3, -55.3, -69.2, -55.5, -71, -55.1, -72.3, -54.5, -73.8, -53, -72.4, -53.7, -71.1, 
    -54.1, -70.3, -52.9, -68.6, -52.6, 0, 0, -58.1, -51.9, -59.9, -51.9, -61.2, -51.9, -60, -51.3, 0, 0, 145.4, -40.8, 146.9, -41, 
    148.3, -40.9, 147.6, -42.9, 146, -43.5, 145.3, -42, 0, 0, 174, -40.9, 173.9, -42.2, 173.1, -43.9, 171.5, -44.2, 170.6, -45.9, 
    169.3, -46.6, 167.8, -46.3, 167, -45.1, 168.3, -44.1, 169.7, -43.6, 171.1, -42.5, 171.9, -41.5, 0, 0, 174.6, -36.2, 175.8, 
    -36.8, 176.8, -37.9, 178.5, -37.7, 178, -39.2, 176.9, -40.1, 176, -41.3, 174.7, -41.3, 174.9, -39.9, 173.9, -39.1, 174.7, -38, 
    174.3, -36.5, 173.6, -35, 0, 0, 166.7, -22.4, 165.5, -21.7, 164.5, -20.1, 165.8, -21.1, 0, 0, 50.1, -13.6, 50.5, -15.2, 49.9, 
    -16.5, 49.4, -18, 49, -19.1, 48.5, -20.5, 47.9, -22.4, 47.5, -23.8, 46.3, -25.2, 44.8, -25.3, 43.8, -24.5, 43.3, -22.8, 43.4, 
    -21.3, 44.4, -20.1, 44, -18.3, 44.3, -16.9, 45.5, -16, 46.9, -15.2, 48.3, -13.8, 49.5, -12.5, 0, 0, 143.9, -14.5, 145.4, -15, 
    145.5, -16.3, 146.2, -17.8, 146.4, -19, 148.2, -20, 149.3, -21.3, 150.7, -22.4, 151.6, -24.1, 152.9, -25.3, 153.2, -26.6, 
    153.6, -28.1, 153.3, -29.5, 153.1, -30.9, 152.5, -32.6, 151.3, -33.8, 150.7, -35.2, 150.1, -36.4, 149.4, -37.8, 147.4, -38.2, 
    146.3, -39, 145, -37.9, 143.6, -38.8, 141.6, -38.3, 140, -37.4, 139.6, -36.1, 138.1, -35.6, 138.2, -34.4, 136.8, -35.3, 137, 
    -33.8, 136, -34.9, 135.2, -33.9, 134.3, -32.6, 133, -32, 131.3, -31.5, 129.5, -31.6, 127.1, -32.3, 125.1, -32.7, 123.7, -33.9, 
    122.2, -34, 120.6, -33.9, 119.3, -34.5, 118, -35.1, 116.6, -35, 115, -34.2, 115.7, -32.9, 115.7, -31.6, 115, -29.5, 114.2, 
    -28.1, 114.2, -26.3, 113.7, -25, 113.5, -23.8, 114.2, -22.5, 115.5, -21.5, 116.7, -20.7, 118.2, -20.4, 119.8, -20, 121.4, 
    -19.2, 122.3, -17.8, 123.4, -17.3, 124.3, -16.3, 125.2, -14.7, 126.6, -14, 127.8, -14.3, 129.4, -14.4, 130.2, -13.1, 131.7, 
    -12.3, 132.4, -11.1, 133.6, -11.8, 135.3, -12.2, 137, -12.4, 136, -13.3, 135.4, -14.7, 136.3, -15.6, 137.6, -16.2, 139.1, 
    -17.1, 140.2, -17.7, 141.3, -16.4, 141.7, -15, 141.5, -13.7, 141.7, -12.4, 142.8, -11.2, 143.2, -12.3, 0, 0, 124, -9.3, 125.9, 
    -8.4, 127.3, -8.4, 125.9, -9.1, 0, 0, 122.8, -8.6, 121.3, -8.9, 119.9, -8.4, 121.3, -8.5, 0, 0, 108.6, -6.8, 110.8, -6.5, 113, 
    -7.6, 114.5, -7.8, 115.7, -8.4, 114.6, -8.8, 112.6, -8.4, 110.6, -8.1, 108.3, -7.8, 106.5, -7.4, 106.1, -5.9, 107.3, -6, 0, 0, 
    151.3, -5.8, 149.7, -6.3, 148.4, -5.4, 149.8, -5.5, 151.1, -5.1, 152.3, -4.3, 0, 0, 152.8, -4.8, 152, -3.5, 150.9, -2.5, 152.2, 
    -3.2, 0, 0, 130.5, -1, 132.4, -0.4, 134.1, -1.2, 135.5, -3.4, 136.3, -2.3, 137.4, -1.7, 139.2, -2.1, 141, -2.6, 142.7, -3.3, 
    145.3, -4.4, 146, -5.5, 147, -6.7, 148.1, -8, 149.3, -9.5, 150.7, -10.6, 148.9, -10.3, 147.1, -9.5, 146, -8.1, 144.7, -7.6, 
    143.3, -8.2, 142.6, -9.3, 141, -9.1, 140.1, -8.3, 138.9, -8.4, 137.6, -8.4, 138.7, -7.3, 137.9, -5.4, 135.2, -4.5, 132.8, -3.7, 
    132, -2.8, 133.7, -2.2, 131.8, -1.6, 0, 0, 121.5, -1, 122.8, -1, 121.5, -1.9, 122.3, -3.5, 122.2, -5.3, 121.6, -4.2, 121, -2.6, 
    120.4, -4.1, 119.8, -5.7, 119.7, -4.5, 118.8, -2.8, 119.3, -1.4, 120, 0.6, 121.7, 1, 124.1, 0.9, 125.2, 1.4, 124.4, 0.4, 122.7, 
    0.4, 121.1, 0.4, 120, -0.5, 0, 0, 128.7, 1.1, 127.7, -0.3, 127.4, 1, 127.9, 2.2, 0, 0, 104.4, -1, 104.9, -2.3, 106.1, -3.1, 
    105.9, -4.3, 105.8, -5.9, 103.9, -5, 102.2, -3.6, 100.9, -2.1, 100.1, -0.7, 99, 1, 97.7, 2.5, 96.4, 3.9, 95.9, 5.4, 97.5, 5.2, 
    98.4, 4.3, 99.7, 3.2, 100.6, 2.1, 102.5, 1.4, 103.8, 0, 0, 0, 117.8, 0.8, 117.5, -0.8, 116.5, -2.5, 116, -3.7, 114.5, -3.5, 
    113.3, -3.1, 111.7, -3, 110.2, -2.9, 109.6, -1.3, 109, 0.4, 109.7, 2, 111.2, 1.9, 111.8, 2.9, 113.7, 3.9, 114.6, 4.9, 116.2, 
    6.1, 117.1, 6.9, 118.3, 5.7, 118.6, 4.5, 117.3, 3.2, 0, 0, 126.4, 8.4, 126.5, 7.2, 125.4, 6.8, 125.4, 5.6, 124.2, 6.2, 123.3, 
    7.4, 121.9, 7.2, 122.9, 8.3, 124.6, 8.5, 125.4, 9.8, 0, 0, 81.2, 6.2, 79.9, 6.8, 79.7, 8.2, 80.8, 9.3, 81.8, 7.5, 0, 0, 118.5, 
    9.3, 117.2, 8.4, 118.4, 9.7, 119.7, 10.6, 0, 0, 121.9, 11.9, 123.1, 11.2, 122, 10.4, 0, 0, 125.8, 11, 124.8, 10.1, 124.9, 11.4, 
    124.3, 12.6, 0, 0, 122.2, 17.8, 122.3, 16.3, 121.5, 15.1, 122.7, 14.3, 123.3, 13, 122, 13.8, 120.6, 14.4, 120.3, 16, 120.4, 
    17.6, 0, 0, -71.6, 19.9, -70, 19.6, -69.2, 18.4, -70.5, 18.2, -71.7, 17.8, -72.8, 18.1, -74.4, 18.7, -72.3, 18.7, 0, 0, 110.3, 
    18.7, 108.7, 18.5, 109.1, 19.8, 111, 19.7, 0, 0, -79.7, 22.8, -78.3, 22.5, -77.1, 21.7, -75.6, 21, -75, 19.9, -76.3, 20, -78.1, 
    20.7, -79.3, 21.6, -80.5, 22, -82.8, 22.7, -84.4, 22.2, -83.3, 23, -81.4, 23.1, 0, 0, 120.7, 22, 120.1, 23.6, 121.8, 24.4, 0, 
    0, 133.8, 33.5, 132.4, 33, 132.9, 34.1, 0, 0, 23.7, 35.7, 25, 35.4, 26.2, 35, 24.7, 35.1, 0, 0, 15.5, 38.2, 15.1, 36.6, 13.8, 
    37.1, 12.4, 37.6, 13.7, 38, 0, 0, 9.8, 40.5, 9.7, 39.2, 8.4, 39.2, 0, 0, 140.6, 36.3, 140.3, 35.1, 139, 34.7, 137.2, 34.6, 
    135.8, 33.5, 135.1, 34.6, 133.3, 34.4, 131, 33.9, 132, 33.1, 130.7, 31, 130.4, 32.3, 129.4, 33.3, 130.9, 34.2, 132.6, 35.4, 
    135.7, 35.5, 137.4, 36.8, 139.4, 38.2, 139.9, 40.6, 141.4, 41.4, 141.9, 39.2, 0, 0, 143.9, 44.2, 145.5, 43.3, 144.1, 43, 143.2, 
    42, 141.6, 42.7, 141.1, 41.6, 139.8, 42.6, 141.4, 43.4, 142, 45.6, 0, 0, -62.3, 49.1, -64.2, 50, -62.9, 49.7, 0, 0, -124, 48.4, 
    -126, 49.2, -127, 49.8, -128.4, 50.8, -126.7, 50.4, -124.9, 49.5, 0, 0, -56.1, 50.2, -54.9, 49.3, -53.5, 49.2, -53, 48.2, 
    -53.1, 46.7, -54, 47.6, -55.3, 47.4, -57.3, 47.6, -59.4, 47.9, -58.4, 49.1, -57.4, 50.7, 0, 0, 143.6, 50.7, 144.7, 49, 143.2, 
    49.3, 142.6, 47.9, 143.5, 46.1, 142.1, 46, 142, 47.8, 142.1, 49.6, 141.6, 51.9, 141.7, 53.3, 142.7, 54.4, 143.3, 52.7, 0, 0, 
    -6.8, 52.3, -8.6, 51.7, -10, 51.8, -9.7, 53.9, -8.3, 54.7, -6.7, 55.2, -6.2, 53.9, 0, 0, -3, 58.6, -4.1, 57.6, -2, 57.7, -2.1, 
    55.9, -0.4, 54.5, 0.5, 52.9, 1.6, 52.1, 0.6, 50.8, -0.8, 50.8, -3, 50.7, -4.5, 50.3, -5.8, 50.2, -4.2, 52.3, -4.6, 53.5, -3.1, 
    53.4, -3.6, 54.6, -4.7, 55.5, -5.6, 56.3, -5.8, 57.8, -4.2, 58.6, 0, 0, -171.7, 63.8, -170.5, 63.7, -168.8, 63.2, -170.3, 63.2, 
    0, 0, -85.2, 65.7, -83.9, 65.1, -81.6, 64.5, -81, 63.4, -82.5, 63.7, -84.1, 63.6, -85.9, 63.6, -87.2, 63.5, -86.2, 64.8, 0, 0, 
    -14.7, 65.8, -13.6, 65.1, -14.9, 64.4, -18.7, 63.5, -20, 63.6, -21.8, 64.4, -24, 64.9, -22.2, 65.4, -23.7, 66.3, -22.1, 66.4, 
    -20.6, 65.7, -19.1, 66.3, -17.8, 66, -16.2, 66.5, 0, 0, -174.6, 67.1, -171.9, 66.9, -170.9, 65.5, -172.5, 65.4, -173, 64.3, 
    -174.7, 64.6, -176, 64.9, -177.2, 65.5, -178.7, 66.1, -180, 65, -180, 69, -177.6, 68.2, 0, 0, -96.3, 68.8, -97.6, 69.1, -98.9, 
    69.7, -97.2, 69.9, 0, 0, -46.6, -1, -44.6, -2.7, -43.4, -2.4, -41.5, -2.9, -40, -2.9, -38.5, -3.7, -36.5, -5.1, -35.2, -5.5, 
    -34.7, -7.3, -35.6, -9.6, -37, -11, -37.7, -12.2, -39, -13.8, -38.9, -15.7, -39.6, -18.3, -39.8, -19.6, -40.8, -20.9, -41.8, 
    -22.4, -43.1, -23, -44.6, -23.4, -46.5, -24.1, -47.6, -24.9, -48.6, -26.6, -48.7, -28.2, -49.6, -29.2, -51.6, -31.8, -52.7, 
    -33.2, -53.8, -34.4, -55.7, -34.8, -57.1, -34.4, -58.5, -34.4, -57.2, -35.3, -56.8, -36.9, -57.7, -38.2, -59.2, -38.7, -62.1, 
    -39.4, -62.1, -40.7, -63.8, -41.2, -65.1, -41.1, -64.4, -42.9, -65.3, -44.5, -66.5, -45, -67.6, -46.3, -66.6, -47, -66, -48.1, 
    -67.2, -48.7, -67.8, -49.9, -69.1, -50.7, -68.6, -52.3, -69.9, -52.5, -71, -53.8, -72.6, -53.5, -73.7, -52.8, -75.3, -51.6, 
    -75.5, -50.4, -75.2, -47.7, -74.1, -46.9, -75.6, -46.6, -74.7, -45.8, -73.2, -44.5, -73.4, -42.1, -74.3, -43.2, -74, -41.8, 
    -73.7, -39.9, -73.5, -38.3, -73.2, -37.1, -72.6, -35.5, -71.9, -33.9, -71.4, -32.4, -71.4, -30.1, -71.5, -28.9, -70.9, -27.6, 
    -70.7, -25.7, -70.4, -23.6, -70.1, -21.4, -70.2, -19.8, -70.4, -18.3, -71.5, -17.4, -73.4, -16.4, -75.2, -15.3, -76.3, -13.5, 
    -77.1, -12.2, -78.1, -10.4, -79, -8.4, -79.8, -7.2, -80.9, -5.7, -81.1, -4, -79.8, -2.7, -81, -2.2, -80.6, -1, -80.1, 0.8, -79, 
    1.7, -77.9, 2.7, -77.5, 4.1, -77.3, 5.8, -78.2, 7.5, -79.1, 9, -80.2, 8.3, -80.9, 7.2, -81.7, 8.1, -83, 8.2, -83.9, 9.3, -85.3, 
    9.8, -85.7, 11.1, -86.7, 12.1, -87.9, 13.1, -89.3, 13.5, -90.6, 13.9, -92.2, 14.5, -93.9, 15.9, -95.3, 16.1, -96.6, 15.7, -98, 
    16.1, -99.7, 16.7, -100.8, 17.2, -102.5, 18, -103.9, 18.7, -105.5, 19.9, -105.3, 21.4, -106, 22.8, -106.9, 23.8, -107.9, 24.5, 
    -109.3, 25.6, -109.8, 26.7, -111.2, 27.9, -112.3, 29.3, -113.1, 31.2, -114.8, 30.9, -114.3, 29.8, -113.3, 28.8, -112.5, 27.5, 
    -111.6, 26.7, -111, 25.3, -110.2, 24.3, -110, 22.8, -110.9, 24, -112.2, 24.7, -112.8, 26.3, -113.8, 26.9, -115.1, 27.7, -114.2, 
    28.6, -115.5, 29.6, -116.3, 30.8, -117.1, 32.5, -117.9, 33.6, -119.4, 34.3, -120.7, 35.2, -121.7, 36.2, -122.5, 37.8, -123.7, 
    39, -124.4, 40.3, -124.2, 42, -124.1, 43.7, -123.9, 45.5, -124.1, 46.9, -124.6, 48.4, -122.3, 47.4, -123, 49, -125.6, 50.4, 
    -127.4, 50.8, -127.9, 52.3, -129.3, 53.6, -131.1, 55.2, -132.3, 56.4, -133.5, 57.2, -135, 58.2, -136.6, 58.2, -137.8, 58.5, 
    -140.8, 59.7, -142.6, 60.1, -144, 60, -145.9, 60.5, -147.1, 60.9, -148.6, 59.9, -150.6, 59.4, -151.9, 59.7, -150.6, 61.3, 
    -152.6, 60.1, -153.3, 58.9, -155.3, 57.7, -156.6, 57, -158.4, 56, -160.3, 55.6, -162.2, 55, -163.8, 55, -161.8, 55.9, -160.1, 
    56.4, -157.7, 57.6, -157, 58.9, -159.1, 58.4, -160.4, 59.1, -162, 58.7, -162.5, 60, -163.8, 59.8, -165.3, 60.5, -165.7, 62.1, 
    -164.6, 63.1, -163.1, 63.1, -161.5, 63.5, -161.4, 64.8, -163.5, 64.6, -165, 64.4, -166.8, 65.1, -168.1, 65.7, -166.7, 66.1, 
    -163.8, 66.1, -162.5, 66.7, -164.4, 67.6, -166.2, 68.9, -164.4, 68.9, -162.9, 69.9, -160.9, 70.4, -158.1, 70.8, -156.6, 71.4, 
    -153.9, 70.9, -152.3, 70.6, -149.7, 70.5, -147.6, 70.2, -144.9, 70, -143.6, 70.2, -141, 69.7, -139.1, 69.5, -137.5, 69, -135.6, 
    69.3, -134.4, 69.6, -132.9, 69.5, -131.4, 69.9, -129.1, 69.8, -127.4, 70.4, -125.8, 69.5, -124.3, 69.4, -122.7, 69.9, -121.5, 
    69.8, -119.9, 69.4, -117.6, 69, -115.2, 68.9, -113.9, 68.4, -115.3, 67.9, -113.5, 67.7, -109.9, 68, -108.9, 67.4, -108.2, 68.7, 
    -107, 68.7, -105.3, 68.6, -103.2, 68.1, -101.5, 67.6, -99.9, 67.8, -97.7, 68.6, -95.5, 68.1, -94.2, 69.1, -95.3, 69.7, -96.4, 
    71.2, -95.2, 71.9, -92.9, 71.3, -92.4, 69.7, -90.6, 68.5, -89.2, 69.3, -88, 68.6, -87.4, 67.2, -86.3, 67.9, -85.5, 69.9, -84.1, 
    69.8, -82.6, 69.7, -81.2, 68.7, -81.4, 67.1, -83.3, 66.4, -84.7, 66.3, -86.1, 66.1, -87.3, 64.8, -88.5, 64.1, -90.7, 63.6, 
    -91.9, 62.8, -93.2, 62, -94.2, 60.9, -94.7, 58.9, -93.2, 58.8, -92.3, 57.1, -90.9, 57.3, -89, 56.9, -87.3, 56, -85, 55.3, 
    -82.3, 55.1, -82.1, 53.3, -81.4, 52.2, -79.9, 51.2, -78.6, 52.6, -79.8, 54.7, -78.2, 55.1, -76.5, 56.5, -77.3, 58.1, -78.5, 
    58.8, -77.8, 60.8, -77.4, 62.6, -74.7, 62.2, -72.9, 62.1, -71.4, 61.1, -69.6, 60.2, -69.3, 59, -67.6, 58.2, -66.2, 58.8, -65.2, 
    59.9, -63.8, 59.4, -62.5, 58.2, -61.8, 56.3, -59.6, 55.2, -57.3, 54.6, -56.2, 53.6, -55.7, 52.1, -57.1, 51.4, -58.8, 51.1, -60, 
    50.2, -61.7, 50.1, -63.9, 50.3, -65.4, 50.3, -67.2, 49.5, -68.5, 49.1, -70.3, 47, -68.7, 48.3, -66.6, 49.1, -65.1, 48.1, -64.5, 
    46.2, -63.2, 45.7, -61.5, 45.9, -60.5, 47, -59.8, 45.9, -61, 45.3, -64.2, 44.3, -65.4, 43.5, -66.2, 44.5, -64.4, 45.3, -67, 
    44.8, -69.1, 44, -70.8, 42.9, -70.6, 41.5, -72.3, 41.3, -73.7, 40.9, -71.9, 40.9, -73.3, 40.6, -74.2, 39.7, -75.5, 39.5, -75.7, 
    37.9, -76.3, 39.2, -76.3, 37.9, -75.9, 36.6, -76.4, 34.8, -78.1, 33.9, -79.2, 33.2, -80.9, 32, -81.5, 30.7, -81, 29.2, -80.5, 
    28, -80.1, 25.8, -81.3, 25.6, -82.2, 26.7, -82.9, 27.9, -82.9, 29.1, -84.1, 30.1, -85.8, 30.2, -87.5, 30.3, -89.2, 30.3, -90.2, 
    29.1, -91.6, 29.7, -93.2, 29.8, -94.7, 29.5, -96.6, 28.3, -97.4, 27.4, -97.1, 25.9, -97.7, 24.3, -97.7, 21.9, -97.2, 20.6, 
    -96.3, 19.3, -94.8, 18.6, -93.5, 18.4, -92, 18.7, -90.8, 19.3, -90.3, 21, -88.5, 21.5, -86.8, 20.8, -87.4, 19.5, -88.1, 18.3, 
    -88.2, 17, -88.1, 15.7, -86.9, 15.8, -85.7, 16, -84.4, 15.8, -83.2, 14.9, -83.5, 13.6, -83.6, 12.3, -83.7, 10.9, -82.5, 9.6, 
    -81.4, 8.8, -79.9, 9.3, -78.5, 9.4, -77.4, 8.7, -76.1, 9.3, -75.5, 10.6, -74.2, 11.3, -72.6, 11.7, -71.3, 11.8, -71.6, 10.4, 
    -71.3, 9.1, -71.4, 11, -69.9, 12.2, -68.9, 11.4, -67.3, 10.5, -65.7, 10.2, -64.3, 10.6, -62.7, 10.4, -61.6, 9.9, -60.2, 8.6, 
    -59.1, 8, -58.1, 6.8, -57.1, 6, -55, 6, -52.9, 5.4, -51.1, 3.7, -49.9, 1, -50.4, 0, -47.8, -0.6, 0, 0, -114.7, 72.7, -112.4, 
    73, -111.1, 72.5, -109, 72.6, -108.2, 71.7, -107.5, 73.2, -105.4, 72.7, -104.5, 71, -102.8, 70.5, -101.1, 69.6, -102.4, 68.8, 
    -104.2, 68.9, -107.1, 69.1, -109, 68.8, -112, 68.6, -113.9, 69, -115.2, 69.3, -116.7, 70.1, -115.1, 70.2, -113.7, 70.2, -112.4, 
    70.4, -114.4, 70.6, -116.5, 70.5, -118.4, 70.9, -116.1, 71.3, -117.7, 71.3, -119.4, 71.6, -117.9, 72.7, 0, 0, -77.3, 72.9, 
    -79.5, 72.7, -80.4, 73.8, -78.1, 73.7, 0, 0, -85.8, 72.5, -84.9, 73.3, -82.3, 73.8, -80.7, 72.1, -77.8, 72.7, -75.6, 72.2, 
    -74.1, 71.3, -72.2, 71.6, -71.2, 70.9, -67.9, 70.1, -67, 69.2, -68.8, 68.7, -66.4, 68.1, -64.9, 67.8, -63.4, 66.9, -62.2, 66.2, 
    -63.9, 65, -65.1, 65.4, -66.7, 66.4, -68.1, 65.7, -67.1, 65.1, -65.3, 64.4, -65, 62.7, -66.3, 62.9, -68.8, 63.7, -67.4, 62.9, 
    -66.2, 61.9, -68.9, 62.3, -71.9, 63.7, -73.4, 64.2, -74.8, 64.4, -77.9, 65.3, -76, 65.3, -73.9, 66.3, -73.3, 68.1, -74.8, 68.6, 
    -76.2, 69.1, -78.2, 69.8, -79.5, 69.9, -81.3, 69.7, -84.9, 70, -87.1, 70.3, -88.5, 71.2, -90.2, 72.2, -88.4, 73.5, 0, 0, 
    -100.4, 73.8, -99.2, 73.6, -98.1, 73, -96.7, 71.7, -98.4, 71.3, -100, 71.7, -102.5, 72.8, -100.4, 72.7, -101.5, 73.4, 0, 0, 
    143.6, 73.2, 142.1, 73.2, 140.8, 73.8, 142.1, 73.9, 0, 0, -93.2, 72.8, -95.4, 72.1, -96, 73.4, -94.5, 74.1, -92.4, 74.1, -90.5, 
    73.9, -92, 73, 0, 0, -120.5, 71.4, -123.6, 71.3, -125.9, 71.9, -124.8, 73, -124.9, 74.3, -121.5, 74.4, -120.1, 74.2, -117.6, 
    74.2, -115.5, 73.5, -116.8, 73.2, -119.2, 72.5, 0, 0, 150.7, 75.1, 149.6, 74.7, 148, 74.8, 146.4, 75.5, 148.2, 75.3, 0, 0, 
    -94.2, 74.6, -96.3, 75.4, -94.9, 75.6, 0, 0, 144.3, 74.8, 140.6, 74.8, 139, 74.6, 137.5, 75.9, 138.8, 76.1, 141.5, 76.1, 0, 0, 
    -97.7, 76.3, -98.2, 75, -99.8, 74.9, -100.9, 75.6, -102.5, 75.6, -101.5, 76.3, -100, 76.6, 0, 0, -107.8, 75.8, -106.3, 75, 
    -109.7, 74.9, -112.2, 74.4, -113.9, 74.7, -111.8, 75.2, -116.3, 75, -117.7, 75.2, -115.4, 76.5, -112.6, 76.1, -110.8, 75.5, 
    -109.1, 75.5, -109.6, 76.8, 0, 0, 56.9, 70.6, 53.4, 71.2, 51.5, 72, 52.4, 72.8, 53.5, 73.7, 55.6, 75.1, 57.9, 75.6, 61.2, 76.3, 
    64.5, 76.4, 66.2, 76.8, 68.2, 76.2, 64.6, 75.7, 61.6, 75.3, 58.5, 74.3, 57, 73.3, 55.6, 71.5, 0, 0, -93.6, 76.8, -91, 76.1, 
    -89.2, 75.6, -87.8, 75.6, -86.4, 75.5, -84.8, 75.7, -82.8, 75.8, -81.1, 75.7, -80.5, 74.7, -81.9, 74.4, -83.2, 74.6, -86.1, 
    74.4, -88.2, 74.4, -89.8, 74.5, -92.8, 75.4, -93.9, 76.3, -96.7, 77.2, 0, 0, -116.3, 76.9, -118, 76.5, -119.9, 76.1, -121.5, 
    75.9, -122.9, 76.1, -121.2, 76.9, -119.1, 77.5, -117.6, 77.5, 0, 0, -1, 49.3, 1.3, 50.1, 2.5, 51.1, 3.8, 51.6, 4.7, 53.1, 7.1, 
    53.7, 8.6, 54.4, 8.1, 55.5, 8.3, 56.8, 9.4, 57.2, 10.6, 57.7, 10.4, 56.2, 9.9, 55, 10.9, 54, 12.5, 54.5, 14.8, 54.1, 16.4, 
    54.5, 18.7, 54.4, 19.9, 54.9, 21.3, 55.2, 21.1, 56.8, 22.5, 57.8, 24.1, 57, 24.4, 58.4, 23.3, 59.2, 24.6, 59.5, 26.9, 59.4, 
    28.1, 60.5, 26.3, 60.4, 24.5, 60.1, 22.9, 59.8, 21.3, 60.7, 21.1, 62.6, 22.4, 63.8, 25.3, 65.5, 23.9, 66, 22.2, 65.7, 21.4, 
    64.4, 19.8, 63.6, 17.8, 62.7, 17.1, 61.3, 18.8, 60.1, 16.8, 58.7, 15.9, 56.1, 14.1, 55.4, 12.6, 56.3, 11.8, 57.4, 10.4, 59.5, 
    8.4, 58.3, 7, 58.1, 5.3, 59.7, 5.9, 62.6, 8.6, 63.5, 10.5, 64.5, 12.4, 65.9, 14.8, 67.8, 16.4, 68.6, 19.2, 69.8, 21.4, 70.3, 
    23, 70.2, 24.5, 71, 26.4, 71, 28.2, 71.2, 31.3, 70.5, 30, 70.2, 32.1, 69.9, 33.8, 69.3, 36.5, 69.1, 40.3, 67.9, 41.1, 66.8, 40, 
    66.3, 38.4, 66, 33.2, 66.6, 34.8, 65.9, 34.9, 64.4, 37, 63.8, 37.2, 65.1, 39.8, 65.5, 42.1, 66.5, 43.9, 66.1, 43.7, 67.4, 43.5, 
    68.6, 46.3, 68.3, 46.3, 66.7, 48.1, 67.5, 50.2, 68, 53.5, 68.2, 55.4, 68.4, 57.3, 68.5, 58.8, 68.9, 59.9, 68.3, 60.6, 69.9, 
    63.5, 69.5, 64.9, 69.2, 69.2, 68.6, 67.3, 69.9, 66.7, 71, 68.5, 71.9, 69.9, 73, 72.8, 72.2, 71.8, 71.4, 72.8, 70.4, 72.6, 69, 
    73.2, 67.7, 72.4, 66.2, 73.9, 66.8, 75.1, 67.8, 74.9, 69, 73.6, 69.6, 74.4, 70.6, 73.1, 71.4, 75.2, 72.9, 75.9, 71.9, 77.6, 
    72.3, 79.7, 72.3, 81.5, 71.8, 80.5, 73.6, 82.3, 73.9, 84.7, 73.8, 86, 74.5, 88.3, 75.1, 90.3, 75.6, 93.2, 76, 96.7, 75.9, 98.9, 
    76.4, 100.8, 76.4, 102, 77.3, 104.4, 77.7, 106.1, 77.4, 104.7, 77.1, 107, 77, 108.2, 76.7, 111.1, 76.7, 114.1, 75.8, 112.8, 75, 
    109.4, 74.2, 110.6, 74, 112.1, 73.8, 114, 73.6, 115.6, 73.8, 119, 73.1, 123.3, 73.7, 125.4, 73.6, 127, 73.6, 128.5, 72, 129.7, 
    71.2, 131.3, 70.8, 132.3, 71.8, 133.9, 71.4, 135.6, 71.7, 138.2, 71.6, 139.1, 72.4, 140.5, 72.8, 150.4, 71.6, 153, 70.8, 157, 
    71, 159, 70.9, 159.7, 69.7, 160.9, 69.4, 162.3, 69.6, 164.1, 69.7, 165.9, 69.5, 167.8, 69.6, 169.6, 68.7, 170.5, 70.1, 173.6, 
    69.8, 175.7, 69.9, 178.6, 69.4, 180, 69, 180, 65, 178.3, 64.1, 179.2, 62.3, 177.4, 62.5, 173.7, 61.7, 172.2, 61, 170.3, 59.9, 
    168.9, 60.6, 166.3, 59.8, 164.9, 59.7, 163.2, 59.2, 162, 58.2, 163.2, 57.6, 162.1, 56.1, 162.1, 54.9, 160, 53.2, 158.2, 51.9, 
    156.4, 51.7, 156, 53.2, 155.4, 55.4, 155.9, 56.8, 156.8, 57.8, 158.4, 58.1, 160.2, 59.3, 161.9, 60.3, 163.7, 61.1, 164.5, 62.6, 
    162.7, 61.6, 160.1, 60.5, 159.3, 61.8, 156.7, 61.4, 155, 59.1, 152.8, 58.9, 151.3, 59.5, 149.8, 59.7, 148.5, 59.2, 145.5, 59.3, 
    142.2, 59, 139, 57.1, 135.1, 54.7, 136.7, 54.6, 138.2, 53.8, 139.9, 54.2, 141.4, 52.2, 140.5, 50, 140.1, 48.4, 138.2, 46.3, 
    136.9, 45.1, 134.9, 43.4, 133.5, 42.8, 132.3, 43.3, 130.8, 42.2, 129.7, 41.6, 129, 40.5, 127.5, 39.8, 128.3, 38.6, 129.2, 37.4, 
    129.5, 35.6, 128.2, 34.9, 126.5, 34.4, 126.6, 35.7, 126.2, 37.7, 124.7, 38.1, 125.4, 39.4, 124.3, 39.9, 122.9, 39.6, 121.6, 
    39.4, 122.2, 40.4, 120.8, 40.6, 119, 39.3, 118.1, 38.1, 119.7, 37.2, 120.8, 37.9, 122.5, 36.9, 120.6, 36.1, 119.2, 34.9, 120.6, 
    33.4, 121.9, 31.7, 122.1, 29.8, 121.1, 28.1, 120.4, 27.1, 119.6, 25.7, 118.7, 24.5, 117.3, 23.6, 114.8, 22.7, 113.2, 22.1, 
    111.8, 21.6, 110.4, 20.3, 109.9, 21.4, 108.1, 21.6, 106.7, 20.7, 105.7, 19.1, 106.4, 18, 107.4, 16.7, 108.9, 15.3, 109.3, 13.4, 
    108.4, 11, 106.4, 9.5, 105.2, 8.6, 105.1, 9.9, 103.5, 10.6, 102.6, 12.2, 101, 13.4, 100, 12.3, 99.5, 10.8, 99.9, 9.2, 100.5, 
    7.4, 101.6, 6.7, 103, 5.5, 103.3, 3.7, 103.9, 2.5, 103.5, 1.2, 102.6, 2, 101.4, 2.8, 100.7, 3.9, 100.2, 5.3, 99.7, 6.8, 99, 
    7.9, 98.3, 9, 98.5, 10.7, 98.4, 12, 98.1, 13.6, 97.8, 14.8, 96.5, 16.4, 95.4, 15.7, 94.2, 16, 94.3, 18.2, 93.7, 19.7, 92.4, 
    20.7, 91.8, 22.2, 90.6, 22.4, 89.4, 22, 88.2, 21.7, 87, 21.5, 86.5, 20.2, 85.1, 19.5, 83.2, 17.7, 81.7, 16.3, 80, 15.1, 80.2, 
    13.8, 79.9, 12.1, 79.3, 10.3, 78.3, 8.9, 77.5, 8, 76.6, 8.9, 75.7, 11.3, 74.9, 12.7, 74.4, 14.6, 73.5, 16, 73.1, 17.9, 72.8, 
    19.2, 72.6, 21.4, 70.5, 20.9, 69.3, 22.8, 67.4, 23.9, 66.4, 25.4, 64.5, 25.2, 62.9, 25.2, 61.5, 25.1, 59.6, 25.4, 57.4, 25.7, 
    56.5, 27.1, 54.7, 26.5, 53.5, 26.8, 52.5, 27.6, 50.9, 28.8, 49.6, 30, 48, 30, 48.4, 28.6, 49.5, 27.1, 50.1, 25.9, 50.8, 24.8, 
    51.3, 26.1, 51.4, 24.6, 52.6, 24.2, 54, 24.1, 55.4, 25.4, 56.5, 26.3, 56.4, 24.9, 57.4, 23.9, 58.7, 23.6, 59.8, 22.3, 58.9, 
    21.1, 57.8, 20.2, 57.2, 18.9, 55.7, 17.9, 54.8, 17, 53.6, 16.7, 52.2, 15.9, 51.2, 15.2, 48.7, 14, 47.4, 13.6, 45.6, 13.3, 44.5, 
    12.7, 43.2, 13.2, 42.9, 14.8, 42.8, 16.3, 42.3, 17.5, 41.2, 18.7, 40.2, 20.2, 39.1, 21.3, 39.1, 22.6, 37.5, 24.3, 36.6, 25.8, 
    35.6, 27.4, 34.6, 28.1, 34.9, 29.5, 34.4, 28.3, 33.1, 28.4, 32.3, 29.8, 33.3, 27.7, 34.1, 26.1, 34.8, 25, 35.5, 23.1, 36.7, 
    22.2, 37.2, 21, 37.1, 19.8, 38.4, 18, 39, 16.8, 39.8, 15.4, 41.7, 13.9, 43.1, 12.7, 43.5, 11.3, 44.6, 10.4, 46.6, 10.8, 48.4, 
    11.4, 49.7, 11.6, 51.1, 12, 51, 10.6, 50.6, 9.2, 50.1, 8.1, 49.5, 6.8, 48.6, 5.3, 47.7, 4.2, 46.6, 2.9, 45.6, 2, 44.1, 1.1, 
    43.1, 0.3, 42, -1, 40.9, -2.1, 40.1, -3.3, 39.2, -4.7, 38.8, -6.5, 39.2, -7.7, 39.5, -9.1, 40.5, -10.8, 40.6, -12.6, 40.8, 
    -14.7, 40.1, -16.1, 38.5, -17.1, 37.4, -17.6, 35.9, -18.8, 34.7, -20.5, 35.6, -22.1, 35.5, -24.1, 34.2, -24.8, 32.9, -26.2, 
    32.6, -27.5, 32.2, -28.8, 30.9, -29.9, 30.1, -31.1, 28.9, -32.2, 27.5, -33.2, 25.9, -33.7, 24.7, -34, 23, -33.9, 21.5, -34.3, 
    20.1, -34.8, 18.9, -34.4, 18.3, -33.3, 18.2, -31.7, 17.1, -29.9, 16.3, -28.6, 15.2, -27.1, 14.7, -25.4, 14.4, -23.9, 14.3, 
    -22.1, 13.4, -20.9, 12.6, -19, 11.7, -17.3, 11.8, -15.8, 12.2, -14.4, 12.7, -13.1, 13.6, -12, 13.4, -10.4, 12.9, -9, 12.9, 
    -7.6, 12.2, -6.3, 11.9, -5, 11.1, -4, 9.4, -2.1, 9, -0.5, 9.5, 1, 9.6, 2.3, 9.4, 3.7, 8.5, 4.8, 6.7, 4.2, 5.4, 4.9, 4.3, 6.3, 
    2.7, 6.3, 1.1, 5.9, -0.5, 5.3, -2, 4.7, -3.3, 5, -4.6, 5.2, -6.5, 4.7, -8, 4.4, -9.9, 5.6, -11.7, 6.9, -13.1, 8.2, -13.7, 9.5, 
    -14.7, 10.7, -15.7, 11.5, -16.7, 12.4, -16.7, 13.6, -17.6, 14.7, -16.7, 15.6, -16.3, 17.2, -16.3, 19.1, -16.5, 20.6, -17, 21.9, 
    -16.3, 23, -15.4, 24.4, -14.8, 25.6, -13.8, 26.6, -12.6, 28, -10.9, 28.8, -9.6, 29.9, -9.4, 32, -8.7, 33.2, -6.9, 34.1, -6.2, 
    35.1, -5.2, 35.8, -3.6, 35.4, -2.2, 35.2, 0, 35.9, 1.5, 36.6, 3.2, 36.8, 4.8, 36.9, 6.3, 37.1, 7.7, 36.9, 9.5, 37.4, 11.1, 
    36.9, 10.9, 35.7, 10.3, 33.8, 11.5, 33.1, 12.7, 32.8, 13.9, 32.7, 15.2, 32.3, 16.6, 31.2, 19.1, 30.3, 20.1, 31, 20.1, 32.2, 
    21.5, 32.8, 22.9, 32.6, 23.9, 32, 25.2, 31.6, 26.5, 31.6, 28.5, 31, 29.7, 31.2, 31, 31.6, 32.2, 31.3, 33.8, 31, 34.8, 32.1, 
    35.5, 33.9, 35.9, 35.4, 35.6, 36.6, 34, 36.2, 31.7, 36.6, 29.7, 36.1, 27.6, 36.7, 26.3, 38.2, 26.2, 39.5, 27.3, 40.4, 29.2, 
    41.2, 31.1, 41.1, 33.5, 42, 35.2, 42, 36.9, 41.3, 38.3, 40.9, 40.4, 41, 41.5, 42.6, 40, 43.4, 38.7, 44.3, 37.4, 45.4, 37.7, 
    46.6, 39.1, 47.3, 37.4, 47, 35.8, 46.6, 35, 45.7, 36.5, 45.5, 35.2, 44.9, 33.3, 44.6, 33.3, 46.1, 31.7, 46.7, 30.4, 46, 28.8, 
    44.9, 28, 43.3, 28, 42, 29, 41.3, 27.6, 41, 26.4, 40.2, 24.9, 40.9, 23.9, 40, 22.6, 40.3, 23.4, 39.2, 23.1, 37.9, 23.2, 36.4, 
    21.7, 36.8, 21.1, 38.3, 20, 39.7, 19.3, 40.7, 18.9, 42.3, 17.5, 42.9, 16, 43.5, 14.9, 44.7, 13.9, 45.6, 12.3, 45.4, 12.6, 44.1, 
    14, 42.8, 15.9, 41.5, 17.5, 40.9, 18.3, 39.8, 16.9, 40.4, 17.1, 38.9, 15.7, 38.2, 15.7, 39.5, 14.7, 40.6, 13.6, 41.2, 12.1, 
    41.7, 10.5, 42.9, 9.7, 44, 7.9, 43.8, 6.5, 43.1, 4.6, 43.4, 3, 42.5, 2.1, 41.2, 0, 40.1, 0, 38.7, -0.7, 37.6, -2.1, 36.7, -4.4, 
    36.7, -5.4, 35.9, -6.5, 36.9, -7.9, 36.8, -8.7, 37.7, -9.5, 38.7, -9, 40.2, -9, 41.9, -9.4, 43, -8, 43.7, -6.8, 43.6, -5.4, 
    43.6, -3.5, 43.5, -1.4, 44, -1.2, 46, -3, 47.6, -4.6, 48.7, -3.3, 48.9, 0, 0, 24.7, 77.9, 22.5, 77.4, 20.8, 78.3, 23.3, 78.1, 
    0, 0, -109.7, 78.6, -110.9, 78.4, -112.5, 78.6, -111, 78.8, 0, 0, -95.8, 78.1, -97.3, 77.9, -98.6, 78.9, -97.3, 78.8, 0, 0, 
    -99.7, 77.9, -101.3, 78, -102.9, 78.3, -104.2, 78.7, -105.5, 79.3, -103.5, 79.2, 0, 0, 105.1, 78.3, 99.4, 77.9, 101.3, 79.2, 
    102.8, 79.3, 0, 0, 18.3, 79.7, 21.5, 79, 18.5, 77.8, 17.1, 76.8, 15.9, 76.8, 14.7, 77.7, 13.2, 78, 10.4, 79.7, 13.7, 79.7, 
    15.5, 80, 17, 80.1, 0, 0, 25.4, 80.4, 27.4, 80.1, 25.9, 79.5, 23, 79.4, 19.9, 79.8, 17.4, 80.3, 20.5, 80.6, 22.9, 80.7, 0, 0, 
    51.1, 80.5, 48.8, 80.2, 47.1, 80.6, 44.8, 80.6, 46.8, 80.8, 49.1, 80.8, 0, 0, 99.9, 78.9, 97.8, 78.8, 95, 79, 92.5, 80.1, 91.2, 
    80.3, 93.8, 81, 95.9, 81.3, 97.9, 80.7, 0, 0, -87, 79.7, -85.8, 79.3, -87.2, 79, -89, 78.3, -90.8, 78.2, -93.1, 79.4, -95, 
    79.4, -96, 80.6, -94.7, 81.2, -92.4, 81.3, -91.1, 80.7, -89.5, 80.5, 0, 0, -68.5, 83.1, -65.8, 83, -63.7, 82.9, -61.9, 82.4, 
    -64.3, 81.9, -67.7, 81.5, -65.5, 81.5, -67.8, 80.9, -69.5, 80.6, -71.2, 79.8, -73.9, 79.4, -76.9, 79.3, -75.5, 79.2, -76.3, 
    78.2, -78.4, 77.5, -79.6, 77, -77.9, 76.8, -80.6, 76.2, -83.2, 76.5, -86.1, 76.3, -87.6, 76.4, -89.6, 77, -87.7, 78, -85, 77.5, 
    -87.2, 78.8, -85.1, 79.3, -86.9, 80.3, -83.4, 80.1, -81.8, 80.5, -84.1, 80.6, -87.6, 80.5, -90.2, 81.3, -91.6, 81.9, -88.9, 
    82.1, -87, 82.3, -85.5, 82.7, -84.3, 82.6, -82.4, 82.9, -81.1, 83, -79.3, 83.1, -75.7, 83.1, -72.8, 83.2, -70.7, 83.2, 0, 0, 
    -27.1, 83.5, -20.8, 82.7, -22.7, 82.3, -26.5, 82.3, -31.4, 82, -27.9, 82.1, -24.8, 81.8, -22.1, 81.7, -23.2, 81.2, -20.6, 81.5, 
    -15.8, 81.9, -12.2, 81.3, -16.9, 80.4, -20, 80.2, -17.7, 80.1, -18.9, 79.4, -19.7, 77.6, -18.5, 77, -20, 76.9, -21.7, 76.6, 
    -19.8, 76.1, -20.7, 75.2, -19.4, 74.3, -20.8, 73.5, -22.2, 73.3, -23.6, 73.3, -22.3, 72.2, -24.8, 72.3, -23.4, 72.1, -21.8, 
    70.7, -23.5, 70.5, -25.2, 70.8, -26.4, 70.2, -23.7, 70.2, -22.3, 70.1, -25, 69.3, -27.7, 68.5, -30.7, 68.1, -32.8, 67.7, -34.2, 
    66.7, -37, 65.9, -38.4, 65.7, -40.7, 64.8, -41.2, 63.5, -42.4, 61.9, -43.4, 60.1, -44.8, 60, -46.3, 60.9, -48.3, 60.9, -49.9, 
    62.4, -51.6, 63.6, -52.3, 65.2, -54, 67.2, -53, 68.4, -52, 69.6, -53.5, 69.3, -54.8, 70.3, -53.4, 70.8, -51.4, 70.6, -54, 71.5, 
    -55.8, 71.7, -54.7, 72.6, -56.1, 73.6, -57.3, 74.7, -58.6, 75.5, -61.3, 76.1, -63.4, 76.2, -66.1, 76.1, -68.5, 76.1, -69.7, 
    76.4, -71.4, 77, -68.8, 77.3, -66.8, 77.4, -71, 77.6, -73.2, 78.4, -69.4, 78.9, -65.3, 79.8, -67.2, 80.5, -62.7, 81.8, -60.3, 
    82, -57.2, 82.2, -53, 81.9, -50.4, 82.4, -48, 82.1, -46.6, 82, -44.5, 81.7, -46.8, 82.6, -43.4, 83.2, -39.9, 83.2, -38.6, 83.5, 
    -35.1, 83.6, 0, 0, -1, -1
};
float const tavak[] = {
    48.6, 41.8, 47.6, 43.7, 46.7, 44.6, 48.6, 45.8, 50, 46.6, 51.2, 47, 53, 46.9, 53, 45.3, 51.3, 45.2, 50.3, 44.3, 51.3, 43.1, 
    52.7, 42.4, 52.8, 41.1, 53.7, 42.1, 53.9, 40.6, 52.7, 40, 53.9, 39, 53.8, 37, 52.3, 36.7, 50.8, 36.9, 49.2, 37.6, 49.4, 39.4, 
    50.1, 40.5, 0, 0, 107.3, 53.4, 108.4, 54.3, 109.7, 55, 109, 53.8, 108.2, 52.8, 106.6, 52.3, 105.2, 51.5, 103.9, 51.9, 105.5, 
    52.3, 0, 0, -99, 53.9, -97.6, 53.4, -96.9, 50.8, -98.2, 52.2, 0, 0, -115.8, 62.8, -113.4, 62, -111, 62.9, -109.1, 62.7, -111.3, 
    62.3, -113.6, 61.1, -116.4, 60.9, -118.2, 61.6, -116.8, 61.3, 0, 0, -79.2, 43.8, -77.6, 44, -76.2, 43.6, -77.7, 43.3, 0, 0, 
    -82.6, 42, -81.1, 42.7, -79.8, 42.3, -81.6, 41.6, 0, 0, -88.6, 48.6, -87.2, 48.7, -86, 48, -85.1, 46.8, -87, 46.5, -87.9, 47.5, 
    -89.6, 46.8, -91.3, 47.3, 0, 0, 34.1, -1, 33, -2.4, 31.8, -1.6, 32.3, 0, 33.9, 0, 0, 0, 30.9, 61.8, 32.6, 60.2, 31.1, 60.1, 0, 
    0, 78.4, 46.3, 77.2, 46.4, 74.8, 46.1, 74.1, 45, 73.7, 46.2, 74.9, 46.8, 77.2, 46.6, 0, 0, 30.5, -8.5, 30.1, -7.3, 29.4, -5.6, 
    29.7, -4.4, 30, -5.9, 30.5, -6.9, 0, 0, 34.7, -14.3, 34.3, -12.9, 34.3, -11.7, 34, -9.5, 34.6, -11.1, 34.7, -12.4, 0, 0, 59.4, 
    45.2, 58.3, 44.5, 58.8, 45.9, 60.1, 45.6, 0, 0, 35.7, 62.3, 36.1, 61, 34.9, 61.6, 34.6, 62.8, 0, 0, -118.1, 65.8, -119.7, 65.4, 
    -121.1, 65.4, -122.4, 65.9, -124.9, 66.2, -120.2, 66.5, 0, 0, -109.7, 59, -111.2, 58.8, -109.1, 59.6, -106.5, 59.3, 0, 0, 
    -79.8, 44.8, -81.3, 44.6, -82.7, 44, -83.9, 43.9, -83.3, 45.2, -84.7, 45.9, -83.2, 46.2, -81.6, 46.1, 0, 0, -84.9, 45.8, -86, 
    44.9, -86.5, 43.7, -86.2, 42.4, -87.5, 41.7, -87.9, 43.2, -88, 44.7, -87, 45.7, 0, 0, -1, -1
};



#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 540
#define LINE_SPACING SCREEN_WIDTH/(360/15) //A koordinátarács vonalak 15 fokontai rajzolásához kell

//A BME GPS koordinátái
#define BME_GPS_X 19.05903
#define BME_GPS_Y 47.47341

void gps_to_world(float bx, float by, float* dx, float* dy) {
    *dx = (bx + 180.0) / 360.0 * SCREEN_WIDTH;
    *dy = SCREEN_HEIGHT-(by + 90.0) / 180.0 * SCREEN_HEIGHT;
}

void draw_world_shape(SDL_Renderer* renderer, const float shape[], int start_i, int end_i, int r,int g,int b,int a) {
    int poly_length = (end_i - start_i) / 2;
    Sint16* sx = (Sint16*)malloc(sizeof(Sint16) * poly_length);
    Sint16* sy = (Sint16*)malloc(sizeof(Sint16) * poly_length);
    
    for (int i = 0; i < poly_length; i++) {
        float curx, cury;
        gps_to_world(shape[start_i + i * 2], shape[start_i + i * 2 + 1], &curx, &cury);
        sx[i] = (Sint16)curx;
        sy[i] = (Sint16)cury;
    }

    filledPolygonRGBA(renderer, sx, sy, poly_length, r, g, b, a);
    aapolygonRGBA(renderer, sx, sy, poly_length, 0, 0,0, 255);

    free(sx);
    free(sy);
}


void draw_map(SDL_Renderer *renderer,const float dims[],int r,int g,int b,int a) {
    int iter = 0;
    int poly_start = 0;
    int poly_end = 0;
    
    while (dims[iter] != -1 || dims[iter + 1] != -1) {
        if (dims[iter] == 0&& dims[iter + 1] == 0) {
            poly_end = iter;
            draw_world_shape(renderer,dims, poly_start, poly_end, r,g,b,a);
            poly_start = iter + 2;
        }
        iter += 2;
    }
}
void draw_lines(SDL_Renderer *renderer) {
    for(int x = 0; x < SCREEN_WIDTH; x += LINE_SPACING) {
        lineRGBA(renderer, x, 0, x, SCREEN_HEIGHT, 0, 0, 0, 156);
    }

    for(int y = 0; y < SCREEN_HEIGHT; y += LINE_SPACING) {
        lineRGBA(renderer, 0, y, SCREEN_WIDTH, y, 0, 0, 0, 156);
    }
}
int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_Log("Az SDL nem indult el: %s", SDL_GetError());
        exit(1);
    }

    SDL_Window *window = SDL_CreateWindow("Világtérkép", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,SCREEN_HEIGHT, 0);
    if (window == NULL) {
        SDL_Log("Az SDL ablak nem lett létrehozva: %s", SDL_GetError());
        exit(1);
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (renderer == NULL) {
        SDL_Log("Az SDL renderer nem lett létrehozva: %s", SDL_GetError());
        exit(1);
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); 
    
    SDL_RenderClear(renderer);
    
    //A kontinensek/földrészek kirajzolása
    draw_map(renderer,vilag,0,255,0,255);
    
    //A tavak kirajzolása
    draw_map(renderer,tavak,0,0,255,255);

    //A koordinátarács kirajzolása
    draw_lines(renderer);

    //A bme jelölése egy vörös ponttal
    float bme_screen_x,bme_screen_y;
    gps_to_world(BME_GPS_X,BME_GPS_Y,&bme_screen_x,&bme_screen_y);
    filledCircleRGBA(renderer,bme_screen_x,bme_screen_y,5,200,0,0,255);

    SDL_RenderPresent(renderer);

    //A program vár a felhasználó kattintására vagy a program bezárására:
    SDL_Event ev;
    int waiting=1;

    while (waiting) {
        if (SDL_WaitEvent(&ev)) {
            if (ev.type == SDL_QUIT || (ev.type == SDL_MOUSEBUTTONDOWN)) {
                waiting = 0;
            }
        }
    }

    SDL_Quit();
    return 0;
}