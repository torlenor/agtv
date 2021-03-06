#ifndef TWITCHAPI_H
#define TWITCHAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrlQuery>
#include <QHash>
#include <QtCore/QJsonObject>


#include <QtCore/QJsonDocument>
#include "generichelper.h"


class TwitchApi : public QObject
{
    Q_OBJECT
public:
    explicit TwitchApi(QObject *parent = 0, QString oauthtoken = "NONE");
    //void setStatusAndGameTitle(const QString &url, QHash<QString, QString> urlParams);
    void setStatusAndGameTitle(QString user, QHash<QString, QString> urlParams);
    void getUser();
    void getStream(QString user);
    void getBookmarkStatus(QString channel);
    void getChannel(QString user);
    void getHost(QString channelid);
    void getChannelAccessToken(QString channel);
    void getPlayList(QString channel, QString token, QString sig);
    QString getPlayListUrl(QString channel, QString token, QString sig);
    void getGame();
    void getKrakenChannel();
    void searchGames(QString searchStr);
    void setOAuthAccessToken(QString oauthtoken);
    void getFollows(QString user);
    void get(QString user);

private:
    void getRequest( const QString &url );
    void getRequestM3u8( const QString &url );
    void getRequestFollows( const QString &url );
    void getRequestBookmark( const QString &url );
    void getRequestStream( const QString &url );
    void getRequestChannel( const QString &url );
    void getRequestHost( const QString &url );
    void getRequestChannelAccessToken( const QString &url );
    void getRequestAuthenticated( const QString &url );
    void putRequest( const QString &url, QHash<QString, QString> urlParams);
    QNetworkAccessManager m_nam;
    QNetworkAccessManager m_namM3u8;
    QNetworkAccessManager m_follows;
    QNetworkAccessManager m_channelaccesstoken;
    QNetworkAccessManager m_bookmark;
    QNetworkAccessManager m_stream;
    QNetworkAccessManager m_channel;
    QNetworkAccessManager m_host;



    QJsonDocument json_buffer;
    QString oAuthAccessToken;


signals:
    void twitchReady( const QJsonDocument &twitchAsJSON );
    void twitchReadyFollows( const QJsonDocument &twitchAsJSON );
    void twitchReadyChannelAccessToken( const QJsonDocument &twitchAsJSON );
    void twitchReadyM3u8( QString m3u8playlist );
    void twitchReadyBookmark( const QJsonDocument &twitchAsJSON );
    void twitchReadyStream( const QJsonDocument &twitchAsJSON );
    void twitchReadyChannel( const QJsonDocument &twitchAsJSON );
    void twitchReadyHost( const QJsonDocument &twitchAsJSON );
    void twitchGameReady( const QJsonObject &twitchAsJSONObj );
    void twitchStreamKeyReady(const QJsonObject &twitchAsJSONObj);
    void networkError( QString errmessage );

public slots:
    void parseNetworkResponse( QNetworkReply *finished );
    void parseNetworkResponseStream( QNetworkReply *finished );
    void parseNetworkResponseHost( QNetworkReply *finished );
    void parseNetworkResponseChannel( QNetworkReply *finished );
    void parseNetworkResponseM3u8( QNetworkReply *finished );
    void parseNetworkResponseFollows( QNetworkReply *finished );
    void parseNetworkResponseBookmark( QNetworkReply *finished );
    void parseNetworkResponseChannelAccessToken( QNetworkReply *finished );


};

#endif // TWITCHAPI_H
